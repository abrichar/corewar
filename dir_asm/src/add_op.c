/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:10:01 by eliajin           #+#    #+#             */
/*   Updated: 2018/07/09 18:15:19 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** On ajoute à buff un element label
*/

void				add_label(char *line, t_parsing **buff)
{
	t_parsing		*tmp;
	t_parsing		*tmp2;

	tmp2 = NULL;
	if ((tmp = (t_parsing*)malloc(sizeof(t_parsing) * 1)))
	{
		tmp->content = ft_strdup(line);
		tmp->size = 0;
		tmp->label = 1;
		tmp->next = NULL;
		if (*buff)
		{
			tmp2 = *buff;
			while (tmp2->next)
				tmp2 = tmp2->next;
			tmp2->next = tmp;
		}
		else
			*buff = tmp;
	}
	else
		msg_error(ERR_MALLOC, 0);
}

/*
** Réécris le format correct de l'instruction
*/

char				*re_write(char *instru)
{
	unsigned int	i;
	unsigned int	j;
	char			*format;

	i = search_char(instru, ' ');
	format = ft_strsub(instru, 0, ft_strlen(instru));
	j = i + 1;
	while (++i < ft_strlen(instru))
	{
		while (instru[i] == ' ')
			i++;
		format[j] = instru[i];
		j++;
	}
	format[j] = '\0';
	return (format);
}

/*
** On ajoute à buff un élément instruction
*/

static void			add_instru2(t_parsing *tmp, t_parsing **buff)
{
	t_parsing *tmp2;

	if (*buff)
	{
		tmp2 = *buff;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}
	else
	{
		*buff = tmp;
		tmp->next = NULL;
	}
}

void				add_instru(char *line, t_parsing **buff)
{
	t_parsing		*tmp;
	char			*name;
	char			*ptr_trash;
	t_op			actual;

	tmp = NULL;
	name = NULL;
	ptr_trash = NULL;
	actual.opcode = 0;
	if ((tmp = (t_parsing*)malloc(sizeof(t_parsing) * 1)))
	{
		ptr_trash = ft_epur_str(line);
		tmp->content = re_write(ptr_trash);
		name = ft_strsub(tmp->content, 0, search_char(tmp->content, ' ') + 1);
		tmp->size = size_instru(tmp, actual);
		tmp->label = 0;
		tmp->next = NULL;
		add_instru2(tmp, buff);
		free(ptr_trash);
	}
	else
		msg_error(ERR_MALLOC, 0);
	if (name)
		free(name);
}

/*
** On ajoute à buff un élément label+instruction
*/

void				add_lab_and_instru(char *line, t_parsing **buff)
{
	int		i;
	char	*sub;
	char	*ptr_trash;

	ptr_trash = NULL;
	i = search_char(line, ' ');
	sub = ft_strsub(line, 0, i + 1);
	ptr_trash = sub;
	sub = ft_epur_str(sub);
	free(ptr_trash);
	add_label(sub, buff);
	if (sub)
		free(sub);
	sub = ft_strsub(line, i + 1, ft_strlen(line) - i);
	ptr_trash = sub;
	sub = ft_epur_str(sub);
	free(ptr_trash);
	add_instru(sub, buff);
	if (sub)
		free(sub);
}
