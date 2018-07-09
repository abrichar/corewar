/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 00:17:45 by eliajin           #+#    #+#             */
/*   Updated: 2018/07/09 20:23:42 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** le caractère que tu cherches, trouver tu dois
*/

int	search_char(char *line, char c)
{
	int i;

	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] == c)
			return (i);
	}
	return (-1);
}

int	ft_is_number(char *line, int begin)
{
	int i;

	i = begin;
	if (line[i] != '-' && ft_isdigit(line[i]) != 1)
		return (0);
	if (line[i] == '-')
		i++;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	isreg(char *line)
{
	char	*tmp;
	int		i;

	tmp = ft_epur_str(line);
	if (tmp[0] != 'r' || ft_strlen(tmp) > 3)
	{
		free(tmp);
		return (0);
	}
	if (ft_strlen(tmp) == 3)
	{
		if (ft_check_len(&tmp, &i) == 0)
			return (0);
	}
	if (ft_strlen(tmp) == 2)
		if (ft_isdigit(tmp[1]) == 0)
		{
			free(tmp);
			return (0);
		}
	ft_strdel(&tmp);
	return (1);
}

int	isdir(char *line)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = ft_epur_str(line);
	if (tmp[0] != DIRECT_CHAR)
	{
		free(tmp);
		return (0);
	}
	if (tmp[1] != LABEL_CHAR)
		if (ft_is_number(tmp, 1) != 1)
		{
			free(tmp);
			return (0);
		}
	if (tmp[1] == LABEL_CHAR)
		while (tmp[++i])
			if (!(ft_strchr(LABEL_CHARS, tmp[i])))
			{
				free(tmp);
				return (0);
			}
	ft_strdel(&tmp);
	return (1);
}

int	isindir(char *line)
{
	char	*tmp;
	int		i;

	i = 1;
	tmp = ft_epur_str(line);
	if (tmp[0] != LABEL_CHAR)
		if (ft_is_number(tmp, 0) != 1)
		{
			free(tmp);
			return (0);
		}
	if (tmp[0] == LABEL_CHAR)
		while (tmp[i])
		{
			if (!(ft_strchr(LABEL_CHARS, tmp[i])))
			{
				free(tmp);
				return (0);
			}
			i++;
		}
	if (tmp)
		free(tmp);
	return (1);
}
