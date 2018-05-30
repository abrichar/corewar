/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 11:22:06 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/10 12:20:35 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short	ft_countnbr(long nbr)
{
	short count;

	if (nbr == -9223372036854775807 - 1)
		return (20);
	if (!nbr)
		return (1);
	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
