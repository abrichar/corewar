/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:45:20 by kgricour          #+#    #+#             */
/*   Updated: 2018/03/05 16:52:43 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_formitoc(char *dest, long int *n, long int *len)
{
	dest[*len] = (*n % 10) + 48;
	*n /= 10;
}

static long int	ft_nbrlenj(long int *n, long int *neg, long int *j)
{
	long int	i;
	long int	tmp;

	i = 0;
	*j = 0;
	tmp = *n;
	if (*n < (long int)0)
	{
		*n = *n * -1;
		*neg = *neg * -1;
	}
	while (tmp != 0)
	{
		tmp /= 10;
		i++;
	}
	if (*neg == (long int)-1)
	{
		*j = *j + 1;
		return (i + 1);
	}
	return (i);
}

static	int		ft_check_long_min(long int *n, long int *neg)
{
	if (*n == (long int)-9223372036854775808U)
	{
		*n = 9223372036854775807;
		*neg = 2;
	}
	return (*n);
}

char			*ft_itoa(long int n)
{
	long int	i;
	long int	j;
	long int	neg;
	long int	nbr;
	char		*str;

	neg = 1;
	j = 0;
	nbr = n;
	i = ft_nbrlenj(&nbr, &neg, &j);
	if (!(str = ft_memalloc(i)))
		return (NULL);
	if (neg == (long int)-1 || neg == (long int)2)
		str[0] = '-';
	ft_check_long_min(&nbr, &neg);
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	str[i] = '\0';
	while (nbr && i-- > j)
		ft_formitoc(str, &nbr, &i);
	(neg == 2) ? str[19] = '8' : neg;
	return (str);
}
