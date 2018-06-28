/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:55:51 by kgricour          #+#    #+#             */
/*   Updated: 2018/03/06 23:31:02 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_zero(char *target)
{
	int i;

	i = 0;
	while (target[i])
	{
		if (target[i] == '0')
		{
			if (ft_isdigit(target[i - 1]))
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

char		*ft_strchrstr(const char *search, char *target, char cmp)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	nbr_char;

	i = 0;
	nbr_char = 0;
	while (search[i])
	{
		j = 0;
		while (target[j])
			if (search[i] == target[j++])
			{
				if (search[i] != '0')
					nbr_char++;
				else if (ft_check_zero(target) == 1)
					nbr_char++;
				break ;
			}
		i++;
	}
	if (nbr_char == i && cmp == '&')
		return (target);
	else if (nbr_char > 0 && cmp == '|')
		return (target);
	return (NULL);
}
