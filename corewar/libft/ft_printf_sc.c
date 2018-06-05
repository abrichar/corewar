/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:58:26 by kgricour          #+#    #+#             */
/*   Updated: 2018/03/06 23:28:52 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_putwstr(wchar_t *s)
{
	char	*new_str;
	char	*tmp2;

	new_str = ft_strnew(0);
	if (s != NULL)
	{
		while (*s)
		{
			tmp2 = ft_putwchar(*s);
			new_str = ft_freejoin(new_str, tmp2, 2);
			s++;
		}
	}
	return (new_str);
}

static void		ft_apply_opt(char *opt, char **str)
{
	char	*ptr_trash;

	if (ft_strchr(opt, 'S') || ft_strchrstr("ls", opt, '&'))
		*str = ft_putwstr((wchar_t *)*str);
	if (ft_strchr(opt, '.'))
		ft_precision((char **)str, opt);
	ptr_trash = *str;
	if (ft_check_point(opt, *str))
	{
		ft_add_space(str, opt);
		ft_strdel(&ptr_trash);
	}
}

static int		ft_isnull(char **new_str, int i)
{
	char *del;

	del = NULL;
	del = ft_strsub(*new_str, 0, i, 1);
	*new_str = ft_freejoin(del, "(null)", 0);
	return (6);
}

int				ft_printf_s(char **new_str, int i, va_list vl, char *opt)
{
	char	*str;
	char	*del;
	char	*ptr_trash;
	int		len;

	str = va_arg(vl, char *);
	if (!(ft_strchr(opt, 'S') || ft_strchrstr("ls", opt, '&')))
		str = ft_strdup((str) ? str : "(null)");
	if (str == NULL)
		return (ft_isnull(new_str, i));
	ft_apply_opt(opt, &str);
	ptr_trash = str;
	len = ft_strlen(str);
	del = ft_strsub(*new_str, 0, i, 1);
	*new_str = ft_freejoin(del, str, 2);
	if (ft_strcmp(ptr_trash, str) != 0)
		ft_strdel(&ptr_trash);
	return (len);
}
