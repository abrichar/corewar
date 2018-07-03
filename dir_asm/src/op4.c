/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:00:24 by eliajin           #+#    #+#             */
/*   Updated: 2018/07/03 16:16:04 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_aff(char *line, int index)
{
	char *tmp;
	char	*ptr_trash;//<------------------kev

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	ptr_trash = tmp;//<------------------kev
	if (ft_strcmp(tmp, "aff") != 0)
	{
		free(tmp);//<------------------kev
		return (0);
	}
	tmp = ft_strsub(line, 3, ft_strlen(line));
	free(ptr_trash);//<------------------kev
	if (isreg(tmp) == 0)
		msg_error(ERR_ARG, index);
	if (tmp)
		free(tmp);
	return (1);
}
