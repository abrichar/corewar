/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:14:46 by kgricour          #+#    #+#             */
/*   Updated: 2018/03/13 18:53:35 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	if (j == 0)
		return ((char *)s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i < j)
	{
		j--;
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
	}
	len = j - i + 1;
	if ((str = ft_strsub((char *)s, i, len, 0)) == NULL)
		return (NULL);
	str[len] = '\0';
	return (str);
}
