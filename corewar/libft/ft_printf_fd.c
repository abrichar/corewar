/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:36:40 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/14 01:31:37 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_skip_space(char *str, int i, int *j)
{
	if (str[i + *j] == ' ')
	{
		while (str[i + *j] == ' ' && str[i + *j])
			*j = *j + 1;
		*j = *j - 1;
	}
}

static void	ft_invalide_conv(char **str, int *i, int *j)
{
	char	*tmp;
	char	*tmp2;
	char	*opt;
	char	*ptr_trash;

	ft_skip_space(*str, *i, j);
	tmp = ft_strsub(*str, *i + *j + 1, ft_strlen(*str), 0);
	while (ft_strchrstr("+-#", *str + *j, '|'))
		*j = *j - 1;
	opt = ft_get_opt(*str + *i);
	if (ft_check_point(opt, ""))
	{
		ptr_trash = tmp;
		ft_add_space(&tmp, opt);
		ft_strdel(&opt);
		ft_strdel(&ptr_trash);
		tmp = ft_strsub(tmp, 1, ft_strlen(tmp), 1);
	}
	tmp2 = ft_strsub(*str, 0, *i, 0);
	ft_strdel(str);
	ft_strdel(&opt);
	*str = ft_freejoin(tmp2, tmp, 2);
	*i = *i - 1;
}

static void	ft_add_word_str(char **str, int *i, int j, va_list vl)
{
	char	*tmp;
	char	*tmp2;
	int		len;

	tmp = NULL;
	len = ft_strlen(*str);
	tmp = ft_strsub(*str, *i + j + 2, len, 0);
	tmp2 = ft_find_conv(*str, i, vl);
	*str = ft_freejoin(tmp2, tmp, 2);
	*i = *i - 1;
}

int			ft_printf_fd(int fd, const char *format, ...)
{
	va_list	vl;
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	new_str = ft_strdup(format);
	va_start(vl, format);
	while (new_str[i])
	{
		j = 0;
		if (new_str[i] == '%')
		{
			if (ft_check_valide_conv(&new_str[i + j + 1], &j) == 1)
				ft_add_word_str(&new_str, &i, j, vl);
			else
				ft_invalide_conv(&new_str, &i, &j);
		}
		i++;
	}
	va_end(vl);
	i = ft_print(fd, new_str);
	ft_strdel(&new_str);
	return (i);
}
