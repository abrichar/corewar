/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:05:29 by eliajin           #+#    #+#             */
/*   Updated: 2018/05/07 12:04:13 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Vérification que chaque op possède les bons arguments
*/

int	ft_live(char *line, int index)
{
	char *tmp;

	if (!(tmp = ft_strsub(line, 0, search_char(line, ' '))))
		msg_error(ERR_MALLOC, 0);
	if (ft_strcmp(tmp, "live") != 0)
		return (0);
	if (!(tmp = ft_strsub(line, 4, ft_strlen(line))))
		msg_error(ERR_MALLOC, 0);
	if (isdir(tmp) == 0)
		msg_error(ERR_ARG, index);
	ft_strdel(&tmp);
	return (1);
}

int	ft_ld(char *line, int index)
{
	char *tmp;
	char **splited;

	if (!(tmp = ft_strsub(line, 0, search_char(line, ' '))))
		msg_error(ERR_MALLOC, 0);
	if (ft_strcmp(tmp, "ld") != 0)
		return (0);
	ft_strdel(&tmp);
	if (!(tmp = ft_strsub(line, 2, ft_strlen(line))))
		msg_error(ERR_MALLOC, 0);
	splited = ft_strsplit(tmp, SEPARATOR_CHAR);
	clear_split(splited);
	if (tab_len(splited) != 2)
		msg_error(ERR_ARG, index);
	if (isdir(splited[0]) == 0 && isindir(splited[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(splited[1]) == 0)
		msg_error(ERR_ARG, index);
	ft_strdel(&tmp);
	free_split(splited);
	return (1);
}

int	ft_st(char *line, int index)
{
	char *tmp;
	char **splited;

	if (!(tmp = ft_strsub(line, 0, search_char(line, ' '))))
		msg_error(ERR_MALLOC, 0);
	if (ft_strcmp(tmp, "st") != 0)
		return (0);
	ft_strdel(&tmp);
	if (!(tmp = ft_strsub(line, 2, ft_strlen(line))))
		msg_error(ERR_MALLOC, 0);
	splited = ft_strsplit(tmp, SEPARATOR_CHAR);
	clear_split(splited);
	if (tab_len(splited) != 2)
		msg_error(ERR_NBR_ARG, index);
	if (isreg(splited[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(splited[1]) == 0 && isindir(splited[1]) == 0)
		msg_error(ERR_ARG, index);
	ft_strdel(&tmp);
	free_split(splited);
	return (1);
}

int	ft_add(char *line, int index)
{
	char *tmp;
	char **splited;

	if (!(tmp = ft_strsub(line, 0, search_char(line, ' '))))
		msg_error(ERR_MALLOC, 0);
	if (ft_strcmp(tmp, "add") != 0)
		return (0);
	ft_strdel(&tmp);
	if (!(tmp = ft_strsub(line, 3, ft_strlen(line))))
		msg_error(ERR_MALLOC, 0);
	splited = ft_strsplit(tmp, SEPARATOR_CHAR);
	clear_split(splited);
	if (tab_len(splited) != 3)
		msg_error(ERR_NBR_ARG, index);
	if (isreg(splited[0]) == 0 && isreg(splited[1]) == 0 &&
		isreg(splited[2]) == 0)
		msg_error(ERR_ARG, index);
	ft_strdel(&tmp);
	free_split(splited);
	return (1);
}

int	ft_sub(char *line, int index)
{
	char *tmp;
	char **splited;

	if (!(tmp = ft_strsub(line, 0, search_char(line, ' '))))
		msg_error(ERR_MALLOC, 0);
	if (ft_strcmp(tmp, "sub") != 0)
		return (0);
	ft_strdel(&tmp);
	if (!(tmp = ft_strsub(line, 3, ft_strlen(line))))
		msg_error(ERR_MALLOC, 0);
	splited = ft_strsplit(tmp, SEPARATOR_CHAR);
	clear_split(splited);
	if (tab_len(splited) != 3)
		msg_error(ERR_NBR_ARG, index);
	if (isreg(splited[0]) == 0 && isreg(splited[1]) == 0 &&
		isreg(splited[2]) == 0)
		msg_error(ERR_ARG, index);
	ft_strdel(&tmp);
	free_split(splited);
	return (1);
}
