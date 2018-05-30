/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:24:50 by eliajin           #+#    #+#             */
/*   Updated: 2018/05/07 12:42:39 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		clear_split(char **splited)
{
	int i;

	i = -1;
	while (++i < tab_len(splited))
		splited[i] = ft_epur_str(splited[i]);
}

int			is_label(char *param)
{
	char	*tmp;
	int		i;

	i = 1;
	tmp = ft_epur_str(param);
	if (tmp[0] != DIRECT_CHAR)
		return (0);
	if (tmp[1] != LABEL_CHAR)
		return (0);
	while (tmp[++i])
		if (!(ft_strchr(LABEL_CHARS, tmp[i])))
			return (0);
	ft_strdel(&tmp);
	return (1);
}

int			check_param(char *param)
{
	if (isreg(param))
		return (REG_CODE);
	if (isdir(param))
		return (DIR_CODE);
	if (isindir(param))
		return (IND_CODE);
	return (0);
}

int			tab_len(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		;
	return (i);
}

uint64_t	reverse_bits(uint64_t val)
{
	uint64_t	res;

	res = 0;
	while (val)
	{
		res <<= 8;
		res |= val & 0xff;
		val >>= 8;
	}
	return (res);
}
