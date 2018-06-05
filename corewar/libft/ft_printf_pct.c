/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:50:59 by kgricour          #+#    #+#             */
/*   Updated: 2018/03/06 23:28:33 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_find_next_pct(char *str, int i, int *j)
{
	int	noopt;

	noopt = 1;
	while (str[i + *j] != '%')
	{
		if (str[i + *j] != ' ')
			noopt = 0;
		*j = *j + 1;
	}
	return (noopt);
}

static char	*ft_add_pct_left(char *opt, char *str, int *len, int i)
{
	char *tmp2;
	char *del;
	char *ptr_trash;

	tmp2 = ft_strnew(0);
	del = tmp2;
	ft_add_space(&tmp2, opt);
	ft_strdel(&del);
	del = tmp2;
	tmp2 = ft_strjoin("%", tmp2 + 1);
	ft_strdel(&del);
	*len = ft_strlen(tmp2);
	del = ft_strsub(str, 0, i, 0);
	ptr_trash = tmp2;
	tmp2 = ft_freejoin(del, ptr_trash, 0);
	ft_strdel(&ptr_trash);
	return (tmp2);
}

static char	*ft_add_pct(char *opt, char *str, int *len, int i)
{
	char *tmp2;
	char *del;
	char *ptr_trash;

	tmp2 = NULL;
	tmp2 = ft_strdup("%");
	if (ft_strchrstr("123456789", opt, '|') && !ft_strchr(opt, '.'))
	{
		del = tmp2;
		ft_add_space(&tmp2, opt);
		ft_strdel(&del);
	}
	*len = ft_strlen(tmp2);
	del = ft_strsub(str, 0, i, 0);
	ptr_trash = tmp2;
	tmp2 = ft_freejoin(del, ptr_trash, 0);
	ft_strdel(&ptr_trash);
	return (tmp2);
}

int			ft_printf_pct(char **new_str, char *opt, int i)
{
	char	*tmp2;
	char	*del;
	int		j;
	int		len;
	int		noopt;

	j = 0;
	len = 0;
	del = *new_str;
	noopt = ft_find_next_pct(*new_str, i, &j);
	if (ft_strchr(opt, '-') != NULL && new_str[0][i + j] == '%')
		tmp2 = ft_add_pct_left(opt, *new_str, &len, i);
	else
		tmp2 = ft_add_pct(opt, *new_str, &len, i);
	ft_strdel(&del);
	*new_str = ft_strdup(tmp2);
	ft_strdel(&tmp2);
	return (len);
}
