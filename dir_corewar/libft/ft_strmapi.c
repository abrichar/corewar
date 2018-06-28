/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 01:13:22 by kgricour          #+#    #+#             */
/*   Updated: 2017/11/15 15:56:17 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str_frsh;

	if (s == NULL)
		return (NULL);
	if ((str_frsh = ft_memalloc(ft_strlen(s))) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str_frsh[i] = (*f)(i, s[i]);
		i++;
	}
	str_frsh[i] = '\0';
	return (str_frsh);
}
