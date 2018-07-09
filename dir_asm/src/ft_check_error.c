/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:53:29 by abrichar          #+#    #+#             */
/*   Updated: 2018/07/09 20:23:43 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_check_error(char **splited, int index)
{
	if (isdir(splited[0]) == 0 && isindir(splited[0])
			== 0 &&
			isreg(splited[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isdir(splited[1]) == 0 && isindir(splited[1])
			== 0 &&
			isreg(splited[1]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(splited[2]) == 0)
		msg_error(ERR_ARG, index);
}

int		ft_check_len(char **tmp, int *i)
{
	char *ptr_trash;

	ptr_trash = NULL;
	if (!ft_is_number(*tmp, 1))
	{
		free(*tmp);
		return (0);
	}
	ptr_trash = ft_strsub(*tmp, 1, 2);
	*i = ft_atoi(ptr_trash);
	free(ptr_trash);
	if (*i > REG_NUMBER)
	{
		free(*tmp);
		return (0);
	}
	return (1);
}
