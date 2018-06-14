/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 00:17:52 by eliajin           #+#    #+#             */
/*   Updated: 2018/05/04 01:29:05 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	checking_op(char *line, t_asm *env, int index)
{
	char *tmp;

	if (env->verif_name == 0)
		msg_error(ERR_NAME, index);
	if (env->verif_com == 0)
		msg_error(ERR_COM, index);
	tmp = rm_comment(line);
	if (is_label_only(tmp) == 1)
		add_label(tmp, &env->buff);
	else if (check_instruction(tmp, index) == 1)
		add_instru(tmp, &env->buff);
	else if (check_lab_and_instru(tmp, index) == 1)
		add_lab_and_instru(tmp, &env->buff);
	else
		msg_error("", index);
}

/*
** Fonction pour checker ligne par ligne
*/

static void	check_line(char *line, char *tmp, t_asm *env, int index)
{
	if (ft_strcmp(line, "") == 0)
		return ;
	if (line[0] == '#')
		return ;
	if (env->verif_name == 0)
		if (is_header(tmp, NAME_CMD_STRING) == 1)
		{
			dump_header(tmp, env, NAME_CMD_STRING, index);
			env->verif_name = 1;
			return ;
		}
	if (env->verif_com == 0 && env->verif_name)
		if (is_header(tmp, COMMENT_CMD_STRING) == 1)
		{
			dump_header(tmp, env, COMMENT_CMD_STRING, index);
			env->verif_com = 1;
			return ;
		}
	checking_op(line, env, index);
}

/*
** fonction de départ du parsing du fichier
*/

void		parsing(char *file, t_asm *env)
{
	char	*line;
	int		index;
	char	*tmp;

	index = 1;
	if (!(env->fd = open(file, O_RDONLY)))
		msg_error(ERR_OPEN, 0);
	while (get_next_line(env->fd, &line) > 0)
	{
		tmp = ft_epur_str(line);
		check_line(tmp, line, env, index);
		free(line);
		free(tmp);
		index++;
	}
	if (close(env->fd) == -1)
		msg_error(ERR_CLOSE, 0);
}
