/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:56:52 by abrichar          #+#    #+#             */
/*   Updated: 2018/07/03 17:39:40 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	index;

	index = 0;
	if ((str = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	while (index < size)
	{
		str[index] = '\0';
		index++;
	}
	str[index] = '\0';
	return (str);
}
