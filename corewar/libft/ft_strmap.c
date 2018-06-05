/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:45:43 by kgricour          #+#    #+#             */
/*   Updated: 2017/11/15 13:42:06 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		str_frsh[i] = (*f)(s[i]);
		i++;
	}
	str_frsh[i] = '\0';
	return (str_frsh);
}
