/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:36:46 by abrichar          #+#    #+#             */
/*   Updated: 2018/05/07 12:38:10 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		size_instru2(char *param, unsigned int *size, t_op actual)
{
	if (check_param(param) == REG_CODE)
		(*size)++;
	else if (check_param(param) == DIR_CODE)
	{
		if (actual.opcode >= 9 && actual.opcode <= 15 &&
			actual.opcode != 13)
			*size += 2;
		else
			*size += 4;
	}
	else
		*size += 2;
}

/*
** Calcule et stocke la taille des buff->content dans buff->size
*/

unsigned int	size_instru(t_parsing *tmp)
{
	char			**splited;
	unsigned int	size;
	int				i;
	t_op			actual;

	size = 0;
	i = search_char(tmp->content, ' ');
	size += 1;
	actual = find_opcode(ft_strsub(tmp->content, 0, i));
	if (actual.opcode != 1 && actual.opcode != 9 &&
		actual.opcode != 12 && actual.opcode != 15)
		size += 1;
	splited = ft_strsplit(ft_strsub(tmp->content, i + 1,
									ft_strlen(tmp->content)), ',');
	clear_split(splited);
	i = -1;
	while (++i < tab_len(splited))
		size_instru2(splited[i], &size, actual);
	free_split(splited);
	return (size);
}

void			verif_size(t_asm *env)
{
	t_parsing		*tmp;
	unsigned int	size;

	env->header->prog_size = 0;
	tmp = env->buff;
	size = tmp->size;
	while (tmp->next)
	{
		tmp = tmp->next;
		size += tmp->size;
	}
	env->header->prog_size = size;
}
