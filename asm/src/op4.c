/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:00:24 by eliajin           #+#    #+#             */
/*   Updated: 2018/05/07 12:17:39 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_aff(char *line, int index)
{
	char *tmp;

	if (!(tmp = ft_strsub(line, 0, search_char(line, ' '))))
		msg_error(ERR_MALLOC, 0);
	if (ft_strcmp(tmp, "aff") != 0)
		return (0);
	ft_strdel(&tmp);
	if (!(tmp = ft_strsub(line, 3, ft_strlen(line))))
		msg_error(ERR_MALLOC, 0);
	if (isreg(tmp) == 0)
		msg_error(ERR_ARG, index);
	ft_strdel(&tmp);
	return (1);
}
