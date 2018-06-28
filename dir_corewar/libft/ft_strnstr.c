/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 23:11:12 by kgricour          #+#    #+#             */
/*   Updated: 2017/11/16 17:03:20 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t tmp;

	i = 0;
	j = 0;
	if (!haystack[i])
		return (NULL);
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] != '\0' && j < len)
	{
		j = 0;
		tmp = i;
		while ((haystack[i] == needle[j]) && (i < len) && (haystack[i]))
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + tmp);
		i = tmp;
		i++;
	}
	return (NULL);
}
