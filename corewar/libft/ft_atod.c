/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:53:15 by kgricour          #+#    #+#             */
/*   Updated: 2017/11/17 19:51:01 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(int nbr)
{
	int pow;
	int i;

	pow = 10;
	i = 0;
	while (i < nbr - 1)
	{
		pow *= 10;
		i++;
	}
	return (pow);
}

double		ft_atod(const char *s)
{
	double	char_to_double;
	double	after_comma;
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	char_to_double = 0.0;
	after_comma = 0.0;
	while (s[i] <= 32)
		i++;
	(s[i] == '-') ? neg++ : neg;
	(s[i] == '-' || s[i] == '+') ? i++ : i;
	while (s[i] >= '0' && s[i] <= '9')
		char_to_double = char_to_double * 10 + s[i++] - '0';
	if (s[i++] == '.' || s[i] == ',')
	{
		while (s[i] >= '0' && s[i] <= '9')
			after_comma = (after_comma * 10 + s[i++] - '0');
		after_comma = after_comma / (ft_pow(ft_nbrlen(after_comma)));
		char_to_double = char_to_double + after_comma;
	}
	(neg == 1) ? char_to_double = -char_to_double : char_to_double;
	return (char_to_double);
}
