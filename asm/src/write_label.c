/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 06:31:50 by abrichar          #+#    #+#             */
/*   Updated: 2018/06/14 19:20:23 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static unsigned int	write_label3(t_parsing *tmp, unsigned int size_to_here,
		unsigned int pos)
{
	ft_putstr("label3\n");
	while (tmp)
	{
		if (tmp->size_to_here == size_to_here)
			break ;
		if (tmp->next == NULL)
			msg_error(NO_LABEL, 0);
		tmp = tmp->next;
	}
	pos += tmp->size;
	return (pos);
}

unsigned int		write_label2(t_parsing *tmp, char *to_search,
		unsigned int size_to_here, t_asm *env)
{
	unsigned int	pos;
	char			*content;

	ft_putstr("label2.1\n");
	while (tmp)
	{
		ft_putstr("boucle0\n");
		while (tmp->label != 1 && tmp->next != NULL)
			tmp = tmp->next;
		ft_putstr("boucle1\n");
		if (tmp->next == NULL)
			msg_error(NO_LABEL, 0);
		ft_putstr("boucle2\n");
		if (!(content = ft_strsub(tmp->content, 0,
								  ft_strlen(tmp->content) - 1)))
			msg_error(ERR_MALLOC, 0);
		ft_putstr("boucle3\n");
		if (ft_strcmp(content, to_search) == 0)
			break ;
		ft_putstr("boucle4\n");
		if (tmp->next == NULL)
			msg_error(NO_LABEL, 0);
		tmp = tmp->next;
	}
	ft_putstr("label2.2\n");
	pos = (tmp->size_to_here - size_to_here);
	tmp = env->buff;
	pos = write_label3(tmp, size_to_here, pos);
	ft_putstr("label2.3\n");
	ft_strdel(&content);
	return (pos);
}

void				write_label(char *dir, t_op actual, t_asm *env,
		unsigned int size_to_here)
{
	unsigned int	pos;
	t_parsing		*tmp;
	char			*to_search;
	unsigned int	max;

	ft_putstr("test\n");
	max = -1;
	to_search = ft_strsub(dir, 2, ft_strlen(dir));
	tmp = env->buff;
	pos = write_label2(tmp, to_search, size_to_here, env);
	if (pos == max)
		pos = 0;
	pos -= ft_atoi(to_search);
	if (actual.opcode >= 9 && actual.opcode <= 15 && actual.opcode != 13)
		ft_putshort_fd(pos, env->fd);
	else
		ft_putint_fd(pos, env->fd);
	tmp = NULL;
	ft_strdel(&to_search);
}
