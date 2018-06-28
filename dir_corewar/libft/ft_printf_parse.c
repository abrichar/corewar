/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 17:33:45 by kgricour          #+#    #+#             */
/*   Updated: 2018/03/06 23:28:07 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_opt(char *s)
{
	char		*opt;
	int			i;
	int			k;
	const char	*flags;

	flags = "#-+jz hl.*";
	i = 1;
	k = 1;
	while (s[i])
	{
		if (ft_strchr(flags, s[i]) || ft_isdigit(s[i]))
			i++;
		else
			break ;
	}
	i++;
	opt = ft_strnew(i);
	while (k < i)
	{
		opt[k - 1] = s[k];
		k++;
	}
	return (opt);
}

int		ft_check_valide_conv(char *s, int *j)
{
	const char *format;
	const char *flags;

	format = "scSbpdDioOuUXxC%";
	flags = "#-+jz hl.*";
	while (s[*j])
	{
		if (ft_strchr(format, s[*j]))
			return (1);
		else if (ft_strchr(flags, s[*j]) || ft_isdigit(s[*j]))
			*j += 1;
		else
			return (0);
	}
	return (0);
}

char	*ft_find_conv(char *new_str, int *i, va_list vl)
{
	char	*opt;

	opt = ft_get_opt(new_str + *i);
	if (ft_strchrstr("%", opt, '&'))
		*i += ft_printf_pct(&new_str, opt, *i);
	else if (ft_strchrstr("sS", opt, '|'))
		*i += ft_printf_s(&new_str, *i, vl, opt);
	else if (ft_strchrstr("cC", opt, '|'))
		*i += ft_printf_c(&new_str, *i, vl, opt);
	else if (ft_strchrstr("dDi", opt, '|'))
		*i += ft_printf_id(&new_str, *i, vl, opt);
	else if (ft_strchrstr("XxOoUubp", opt, '|'))
		*i += ft_printf_xobup(&new_str, *i, vl, opt);
	ft_strdel(&opt);
	return (new_str);
}
