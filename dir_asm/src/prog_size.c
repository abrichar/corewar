/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:12:40 by abrichar          #+#    #+#             */
/*   Updated: 2018/07/09 18:12:41 by abrichar         ###   ########.fr       */
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

static void		ft_act_opcode(t_op actual, unsigned int *size)
{
	if (actual.opcode != 1 && actual.opcode != 9 &&
		actual.opcode != 12 && actual.opcode != 15)
		*size += 1;
}

static void		ft_free_instru(char ***splited, char ***ptr_trash)
{
	int		i;
	char	**splited2;
	char	**ptr2;

	splited2 = *splited;
	ptr2 = *ptr_trash;
	i = 0;
	while (ptr2[i])
	{
		free(ptr2[i]);
		i++;
	}
	if (splited2)
		free(splited2);
}

unsigned int	size_instru(t_parsing *tmp, t_op actual)
{
	char			**splited;
	char			*str_sub;
	char			**ptr_trash;
	unsigned int	size;
	int				i;

	size = 0;
	str_sub = NULL;
	i = search_char(tmp->content, ' ');
	size += 1;
	str_sub = ft_strsub(tmp->content, 0, i);
	actual = find_opcode(str_sub);
	free(str_sub);
	ft_act_opcode(actual, &size);
	str_sub = ft_strsub(tmp->content, i + 1, ft_strlen(tmp->content));
	splited = ft_strsplit(str_sub, ',');
	ptr_trash = splited;
	free(str_sub);
	clear_split(splited);
	i = -1;
	while (++i < tab_len(splited))
		size_instru2(splited[i], &size, actual);
	ft_free_instru(&splited, &ptr_trash);
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
