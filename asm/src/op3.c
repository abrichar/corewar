/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:29:30 by eliajin           #+#    #+#             */
/*   Updated: 2018/05/03 09:17:04 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_sti(char *line, int index)
{
	char *tmp;
	char **splited;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	if (ft_strcmp(tmp, "sti") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	splited = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(splited) != 3)
		msg_error(ERR_NBR_ARG, index);
	if (isreg(splited[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(splited[1]) == 0 && isindir(splited[1]) == 0 &&
		isdir(splited[1]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(splited[2]) == 0 && isdir(splited[2]) == 0)
		msg_error(ERR_ARG, index);
	free(tmp);
	free_split(splited);
	return (1);
}

int	ft_fork(char *line, int index)
{
	char	*tmp;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	if (ft_strcmp(tmp, "fork") != 0)
		return (0);
	tmp = ft_strsub(line, 4, ft_strlen(line));
	if (isdir(tmp) == 0)
		msg_error(ERR_ARG, index);
	free(tmp);
	return (1);
}

int	ft_lld(char *line, int index)
{
	char *tmp;
	char **splited;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	if (ft_strcmp(tmp, "lld") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	splited = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(splited) != 2)
		msg_error(ERR_NBR_ARG, index);
	if (isdir(splited[0]) == 0 && isindir(splited[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(splited[1]) == 0)
		msg_error(ERR_ARG, index);
	free(tmp);
	free_split(splited);
	return (1);
}

int	ft_lldi(char *line, int index)
{
	char *tmp;
	char **splited;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	if (ft_strcmp(tmp, "lldi") != 0)
		return (0);
	tmp = ft_strsub(line, 4, ft_strlen(line));
	splited = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(splited) != 3)
		msg_error(ERR_NBR_ARG, index);
	if (isreg(splited[0]) == 0 && isindir(splited[0]) == 0 &&
		isdir(splited[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(splited[1]) == 0 && isdir(splited[1]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(splited[2]) == 0)
		msg_error(ERR_ARG, index);
	free(tmp);
	free_split(splited);
	return (1);
}

int	ft_lfork(char *line, int index)
{
	char *tmp;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	if (ft_strcmp(tmp, "lfork") != 0)
		return (0);
	tmp = ft_strsub(line, 5, ft_strlen(line));
	if (isdir(tmp) == 0)
		msg_error(ERR_ARG, index);
	free(tmp);
	return (1);
}
