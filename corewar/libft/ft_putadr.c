/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:33:46 by kgricour          #+#    #+#             */
/*   Updated: 2018/03/06 17:46:02 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_type_x(char **base, char *opt)
{
	if (ft_strchr(opt, 'X'))
		*base = "0123456789ABCDEF";
	else
		*base = "0123456789abcdef";
}

static void	ft_apply_opt(char *opt, t_hex *hex)
{
	char	*tmp;
	char	*ptr_trash;

	tmp = "";
	(ft_strchr(opt, '.') || (ft_strchrstr("#x", opt, '|') &&
	!ft_strchr(opt, '-'))) ? ft_precision(&hex->res, opt) : 1;
	if (hex->res[0] != '\0' || ft_strchr(opt, 'p'))
	{
		if ((ft_strchr(opt, '#') && ft_strchr(opt, 'x')) || ft_strchr(opt, 'p'))
			tmp = "0x";
		else if (ft_strchr(opt, '#') && ft_strchr(opt, 'X'))
			tmp = "0X";
		else if (ft_strchrstr("oO", opt, '|') && ft_strchr(opt, '#'))
			tmp = "0";
	}
	(ft_strchr(opt, 'p') && hex->res[0] == '\0') ? tmp = "0x0" : tmp;
	if (ft_strchr(opt, 'p') && hex->res[0] == '\0' && ft_strchr(opt, '.'))
		tmp = "0x";
	hex->res = ft_freejoin(tmp, hex->res, 1);
	if (hex->res[0] == '\0' && (!ft_strchr(opt, '.') || ft_strchr(opt, '#')))
	{
		ptr_trash = hex->res;
		hex->res = ft_strdup("0");
		ft_strdel(&ptr_trash);
	}
}

static void	ft_insert_space(char **res, char *opt)
{
	char				*ptr_trash;

	ptr_trash = *res;
	ft_add_space(res, opt);
	ft_strdel(&ptr_trash);
}

char		*ft_putadr(unsigned long long adr, char *opt, int base)
{
	t_hex				*hex;
	char				*ret;
	int					i;

	i = ft_count_nbr(adr, base);
	if (!(hex = (t_hex *)malloc(sizeof(t_hex))))
		return (NULL);
	hex->res = (char *)malloc(sizeof(char) * (i + 1));
	hex->res[i] = '\0';
	ft_check_type_x(&hex->base, opt);
	while (adr != 0)
	{
		i--;
		hex->res[i] = hex->base[adr % base];
		adr /= (unsigned long long)base;
	}
	ft_apply_opt(opt, hex);
	if (ft_check_point(opt, hex->res) == 1)
		ft_insert_space(&hex->res, opt);
	ret = ft_strdup(hex->res);
	ft_strdel(&hex->res);
	free(hex);
	return (ret);
}
