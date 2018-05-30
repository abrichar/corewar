/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:23:15 by eliajin           #+#    #+#             */
/*   Updated: 2018/05/07 10:26:15 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** initialise le tableau
*/

static void	get_in_tab(int (*tab[16])(char *, int))
{
	if (tab)
	{
		tab[0] = ft_live;
		tab[1] = ft_ld;
		tab[2] = ft_st;
		tab[3] = ft_add;
		tab[4] = ft_sub;
		tab[5] = ft_and;
		tab[6] = ft_or;
		tab[7] = ft_xor;
		tab[8] = ft_zjmp;
		tab[9] = ft_ldi;
		tab[10] = ft_sti;
		tab[11] = ft_fork;
		tab[12] = ft_lld;
		tab[13] = ft_lldi;
		tab[14] = ft_lfork;
		tab[15] = ft_aff;
	}
}

/*
** Regarde si que label
*/

int			is_label_only(char *line)
{
	int		ptr;
	size_t	i;
	size_t	length;

	i = -1;
	length = ft_strlen(line) - 1;
	if (line[length] != LABEL_CHAR)
		return (0);
	while (++i < length - 1)
		if ((ptr = search_char(LABEL_CHARS, line[i])) == -1)
			return (0);
	return (1);
}

/*
** Regarde si que instruction
*/

int			check_instruction(char *line, int index)
{
	int (*tab[16])(char*, int);
	int i;

	i = -1;
	get_in_tab(tab);
	while (++i < 16)
	{
		if (search_char(line, ' ') == -1)
			return (0);
		if (tab[i](line, index) == 1)
			return (1);
	}
	return (0);
}

/*
** Regarde si les deux
*/

int			check_lab_and_instru(char *line, int index)
{
	int		i;
	char	*sub;
	char	*clean;

	i = search_char(line, LABEL_CHAR);
	if (i == -1 || i == 0)
		return (0);
	if (!(sub = ft_strsub(line, 0, i + 1)))
		msg_error(ERR_MALLOC, 0);
	if (is_label_only(sub) == 0)
		return (0);
	ft_strdel(&sub);
	if (!(sub = ft_strsub(line, i + 1, ft_strlen(line) - i)))
		msg_error(ERR_MALLOC, 0);
	clean = ft_epur_str(sub);
	ft_strdel(&sub);
	if (check_instruction(clean, index) == 0)
		return (0);
	ft_strdel(&clean);
	return (1);
}
