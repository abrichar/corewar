/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:11:06 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/16 18:42:13 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *s, unsigned int start, size_t len, int del)
{
	size_t	i;
	char	*str_frsh;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((str_frsh = (char *)ft_memalloc(len)) == NULL)
		return (NULL);
	str_frsh[len] = '\0';
	while (i < len && s[start])
	{
		str_frsh[i] = s[start];
		i++;
		start++;
	}
	if (del == 1)
		ft_strdel(&s);
	return (str_frsh);
}
