/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:15:56 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 02:03:18 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n, int mode)
{
	unsigned char	*str;
	unsigned int	*nbr;

	if (mode == 1)
	{
		str = s;
		while (n--)
			str[n] = 0;
	}
	else if (mode == 2)
	{
		nbr = s;
		while (n--)
			nbr[n] = 0;
	}
}
