/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:56:50 by kgricour          #+#    #+#             */
/*   Updated: 2018/04/24 22:09:56 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlenc(const char *str, char c)
{
	int			i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static int		ft_countwords(const char *str, char c)
{
	int			words;
	int			i;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			words++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
	}
	return (words);
}

static char		*ft_makeword(const char *str, int *j, char c)
{
	char		*res;
	int			i;

	if (!(res = (char *)malloc(sizeof(char) * (ft_strlenc(&str[*j], c) + 1))))
		return (NULL);
	i = 0;
	while (str[*j] != c && str[*j] != '\0')
	{
		res[i] = str[*j];
		i++;
		*j = *j + 1;
	}
	res[i] = '\0';
	return (res);
}

char			**ft_strsplit(const char *str, char c)
{
	char		**res;
	int			i;
	int			j;

	if (str == NULL)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (ft_countwords(str, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_countwords(str, c) && str[j] != '\0')
	{
		if (str[j] == c)
			j++;
		else
		{
			res[i] = ft_makeword(str, &j, c);
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}
