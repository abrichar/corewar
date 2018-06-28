/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:26:08 by kgricour          #+#    #+#             */
/*   Updated: 2018/03/06 23:26:59 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_wchar_to_str(char **c_to_s, va_list vl)
{
	if ((*c_to_s = ft_putwchar((wchar_t)va_arg(vl, int))) == 0)
	{
		*c_to_s = ft_strnew(1);
		*c_to_s[0] = '\0';
	}
}

int				ft_printf_c(char **new_str, int i, va_list vl, char *opt)
{
	char	*c_to_s;
	char	*ptr_trash;
	char	*del;
	int		len;

	len = 0;
	c_to_s = ft_strnew(1);
	if (ft_strchr(opt, 'C') || ft_strchrstr("lc", opt, '&'))
	{
		ft_strdel(&c_to_s);
		ft_wchar_to_str(&c_to_s, vl);
	}
	else if (ft_strchr(opt, 'c'))
		c_to_s[0] = va_arg(vl, int);
	(c_to_s[0] == '\0') ? c_to_s[0] = '\1' : c_to_s[0];
	len = ft_strlen(c_to_s);
	if (ft_check_point(opt, c_to_s))
	{
		ptr_trash = c_to_s;
		ft_add_space((char **)&c_to_s, opt);
		ft_strdel(&ptr_trash);
	}
	del = ft_strsub(*new_str, 0, i, 1);
	*new_str = ft_freejoin(del, c_to_s, 2);
	return (len);
}
