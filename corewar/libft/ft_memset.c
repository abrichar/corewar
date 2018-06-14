/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:25:05 by kgricour          #+#    #+#             */
/*   Updated: 2017/11/09 20:23:24 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;

	str = (unsigned char*)b;
	if (len == 0)
		return (str);
	while (len--)
		str[len] = c;
	return (str);
}
