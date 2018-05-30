/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 22:25:42 by eliajin           #+#    #+#             */
/*   Updated: 2018/05/07 13:06:26 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static unsigned int		write_octetcodage(t_op actual, char *arg)
{
	char			**splited;
	unsigned int	param1;
	unsigned int	param2;
	unsigned int	param3;

	param1 = 0;
	param2 = 0;
	param3 = 0;
	splited = ft_strsplit(arg, SEPARATOR_CHAR);
	clear_split(splited);
	if (actual.opcode != 1 && actual.opcode != 9 && actual.opcode != 12
		&& actual.opcode != 15)
	{
		if (actual.nb_arg >= 1)
			param1 = check_param(splited[0]) << 6;
		if (actual.nb_arg >= 2)
			param2 = check_param(splited[1]) << 4;
		if (actual.nb_arg == 3)
			param3 = check_param(splited[2]) << 2;
	}
	free_split(splited);
	return (param1 + param2 + param3);
}

t_op					find_opcode(char *name)
{
	t_op	*tab_op;
	int		i;

	i = -1;
	tab_op = get_ops();
	while (ft_strcmp(tab_op[++i].name, name) != 0)
		;
	return (tab_op[i]);
}

static void				write_body2(t_asm *env, char **splited,
									int i, t_parsing *tmp)
{
	t_op			actual;
	unsigned int	to_write;

	if (splited[i])
	{
		actual = find_opcode(splited[i++]);
		write(env->fd, &actual.opcode, sizeof(int) / 4);
		to_write = write_octetcodage(actual, splited[i]);
		if (to_write != 0)
			write(env->fd, &to_write, sizeof(int) / 4);
		write_params(env, splited[i], actual, tmp->size_to_here);
	}
}

static void				write_body(t_asm *env)
{
	char			**splited;
	int				i;
	t_parsing		*tmp;

	tmp = env->buff;
	while (tmp)
	{
		while (tmp->label == 1 && tmp->next)
			tmp = tmp->next;
		i = 0;
		splited = ft_strsplit(tmp->content, ' ');
		clear_split(splited);
		if (splited[i][ft_strlen(splited[i]) - 1] == LABEL_CHAR)
			i++;
		write_body2(env, splited, i, tmp);
		tmp = tmp->next;
		free_split(splited);
	}
}

void					write_out(t_asm *env)
{
	env->fd = open(env->champ_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	ft_putint_fd(env->header->magic, env->fd);
	write(env->fd, env->header->prog_name, PROG_NAME_LENGTH + 4);
	ft_putint_fd(env->header->prog_size, env->fd);
	write(env->fd, env->header->comment, COMMENT_LENGTH + 4);
	write_body(env);
	close(env->fd);
}
