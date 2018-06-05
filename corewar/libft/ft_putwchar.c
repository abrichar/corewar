/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 00:09:42 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/21 11:55:53 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_putwchar_one(wchar_t str, char *c)
{
	c = ft_strnew(2);
	c[0] = str;
	c[1] = '\0';
	return (c);
}

static char	*ft_putwchar_two(wchar_t str, char *c)
{
	c = ft_strnew(3);
	c[0] = ((str >> 6) & 0b11111) | 0xc0;
	c[1] = (str & 0b111111) | 0x80;
	c[2] = '\0';
	return (c);
}

static char	*ft_putwchar_three(wchar_t str, char *c)
{
	c = ft_strnew(4);
	c[0] = ((str >> 12) & 0b1111) | 0xe0;
	c[1] = ((str >> 6) & 0b111111) | 0x80;
	c[2] = (str & 0b111111) | 0x80;
	c[3] = '\0';
	return (c);
}

static char	*ft_putwchar_four(wchar_t str, char *c)
{
	c = ft_strnew(5);
	c[0] = ((str >> 18) & 0b111) | 0xf0;
	c[1] = ((str >> 12) & 0b111111) | 0x80;
	c[2] = ((str >> 6) & 0b111111) | 0x80;
	c[3] = (str & 0b111111) | 0x80;
	c[4] = '\0';
	return (c);
}

char		*ft_putwchar(wchar_t str)
{
	int		i;
	char	*c;

	c = NULL;
	i = 0;
	if (str > 0x00 && str <= 0x7F)
		c = ft_putwchar_one(str, c);
	else if (str > 0x80 && str <= 0x7FF)
		c = ft_putwchar_two(str, c);
	else if (str > 0x800 && str <= 0xFFFF)
		c = ft_putwchar_three(str, c);
	else if (str > 0x10000 && str <= 0x10FFFF)
		c = ft_putwchar_four(str, c);
	return (c);
}
