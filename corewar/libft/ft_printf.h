/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:03:11 by kgricour          #+#    #+#             */
/*   Updated: 2018/05/31 19:10:59 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <wchar.h>
# include <stdarg.h>
# include "libft.h"
# include <inttypes.h>

typedef struct	s_hex
{
	char *base;
	char *res;
}				t_hex;

/*
** __attribute__((format(printf, 1, 2)))
*/
int				ft_printf_fd(int fd, const char *format, ...);
int				ft_printf_s(char **new_str, int i, va_list vl, char *opt);
int				ft_printf_c(char **new_str, int i, va_list vl, char *opt);
int				ft_printf_id(char **new_str, int i, va_list vl, char *opt);
int				ft_printf_xobup(char **new_str, int i, va_list vl, char *opt);
void			ft_add_space(char **tmp2, char *opt);
int				ft_printf_pct(char **new_str, char *opt, int i);
int				ft_check_valide_conv(char *s, int *j);
char			*ft_get_opt(char *s);
void			ft_add_space(char **tmp2, char *opt);
void			ft_add_plus(char *opt, char **tmp2);
int				ft_precision(char **str, char *opt);
char			*ft_putwchar(wchar_t str);
char			*ft_get_opt(char *s);
int				ft_print(int fd, char *str);
int				ft_check_valide_conv(char *s, int *j);
char			*ft_find_conv(char *new_str, int *i, va_list vl);
int				ft_check_point(char *opt, char *str);
int				ft_count_nbr(unsigned long long value, int base);

#endif
