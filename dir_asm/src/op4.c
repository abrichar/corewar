/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:00:24 by eliajin           #+#    #+#             */
/*   Updated: 2018/07/04 02:56:39 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_aff(char *line, int index)
{
	char *tmp;
	char	*ptr_trash;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	ptr_trash = tmp;
	if (ft_strcmp(tmp, "aff") != 0)
	{
		free(tmp);
		return (0);
	}
	tmp = ft_strsub(line, 3, ft_strlen(line));
	free(ptr_trash);
	if (isreg(tmp) == 0)
		msg_error(ERR_ARG, index);
	if (tmp)
		free(tmp);
	return (1);
}
