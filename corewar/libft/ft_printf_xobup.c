/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:22:02 by kgricour          #+#    #+#             */
/*   Updated: 2018/03/06 23:29:25 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_find_base(char *opt)
{
	int	b;

	b = 0;
	if (ft_strchr(opt, 'b'))
		b = 2;
	else if (ft_strchrstr("oO", opt, '|'))
		b = 8;
	else if (ft_strchrstr("uU", opt, '|'))
		b = 10;
	else if (ft_strchrstr("xXp", opt, '|'))
		b = 16;
	return (b);
}

static char	*ft_cast_param_xobup(va_list vl, char *opt)
{
	char	*adr;
	char	*tmp2;
	int		b;

	b = ft_find_base(opt);
	if (ft_strchrstr("UOl", opt, '|'))
		tmp2 = ft_putadr(va_arg(vl, unsigned long int), opt, b);
	else if (ft_strchr(opt, 'p'))
		tmp2 = ft_putadr((unsigned long long)va_arg(vl, char *), opt, b);
	else if ((adr = ft_strchr(opt, 'h')) && ft_strchr(adr + 1, 'h'))
		tmp2 = ft_putadr((unsigned char)va_arg(vl, unsigned int), opt, b);
	else if ((adr = ft_strchr(opt, 'l')) && ft_strchr(adr + 1, 'l'))
		tmp2 = ft_putadr(va_arg(vl, unsigned long long int), opt, b);
	else if (ft_strchr(opt, 'z'))
		tmp2 = ft_putadr(va_arg(vl, size_t), opt, b);
	else if (ft_strchr(opt, 'j'))
		tmp2 = ft_putadr((unsigned long long)va_arg(vl, intmax_t), opt, b);
	else if (ft_strchr(opt, 'h'))
		tmp2 = ft_putadr((unsigned short int)va_arg(vl, unsigned int), opt, b);
	else
		tmp2 = ft_putadr(va_arg(vl, unsigned int), opt, b);
	return (tmp2);
}

int			ft_printf_xobup(char **new_str, int i, va_list vl, char *opt)
{
	char	*tmp;
	char	*adr;
	int		len;

	tmp = ft_cast_param_xobup(vl, opt);
	if ((adr = ft_strchr(opt, '.')) && (*(adr + 1) == '0' ||
	!ft_isdigit(*(adr + 1))) && ft_strcmp(tmp, "0") == 0 && ft_strchr(opt, 'x'))
	{
		ft_strdel(&tmp);
		tmp = ft_strdup("");
	}
	len = ft_strlen(tmp);
	*new_str = ft_strsub(*new_str, 0, i, 1);
	*new_str = ft_freejoin(*new_str, tmp, 2);
	return (len);
}
