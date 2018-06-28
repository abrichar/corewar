/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 23:41:34 by kgricour          #+#    #+#             */
/*   Updated: 2018/03/06 23:13:37 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_edit_nbr_x(char **str, char *opt)
{
	int		i;
	int		nbr;
	char	*adr;

	i = 0;
	nbr = 0;
	if (opt[0] == '0' || opt[1] == '0')
		i++;
	if ((adr = ft_strchr(opt, '.')))
		nbr = ft_atoi(adr + 1) - ft_strlen(*str);
	else if (ft_strchrstr("0", &opt[i], '&'))
		nbr = ft_atoi(opt + i + 1) - ft_strlen(*str);
	if (ft_strchr(opt, '#') && ft_strchrstr("xX", opt, '|') &&
		!ft_strchr(opt, '.'))
		nbr -= 2;
	if (nbr < 0)
		nbr = 0;
	return (nbr);
}

static int	ft_edit_nbr_sd(char **str, char *opt, int mode)
{
	int		nbr;
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (opt[i] && opt[i] != '.')
		i++;
	nbr = ft_atoi(opt + i + 1);
	if ((int)ft_strlen(*str) > nbr || ft_strchrstr("Ss", opt, '|'))
	{
		if (ft_strchr(*str, '-') && !ft_strchr(opt, 'S'))
			nbr--;
		*str = ft_strsub(*str, 0, nbr, 1);
		return (0);
	}
	if (mode == 1)
		nbr = nbr - ft_strlen(*str);
	else if (mode == 2)
		nbr = nbr - ft_strlen(*str) + 1;
	else if (mode == 3)
		nbr = nbr - ft_strlen(*str) - 1;
	return (nbr);
}

static void	ft_add_preci(int nbr, char *opt, char **str)
{
	char	c;
	char	*zero;

	c = '0';
	zero = NULL;
	if (ft_strchrstr("sS", opt, '|'))
		c = ' ';
	zero = ft_strnew(nbr);
	ft_memset(zero, c, nbr);
	*str = ft_freejoin(zero, *str, 2);
}

int			ft_precision(char **str, char *opt)
{
	int		nbr;

	nbr = ft_edit_nbr_x(str, opt);
	if (!ft_strchr(*str, '-') || ft_strchr(opt, 'S'))
	{
		if (ft_strchrstr("sS", opt, '|'))
			nbr = ft_edit_nbr_sd(str, opt, 1);
		else if (opt[0] == '0' && ft_strchrstr("d+", opt, '&'))
			nbr = ft_edit_nbr_sd(str, opt, 3);
	}
	if (ft_strchr(*str, '-'))
		if (ft_strchrstr("dD", opt, '|') && ft_strchr(opt, '.'))
			nbr = ft_edit_nbr_sd(str, opt, 2);
	if (ft_strchrstr("#.o", opt, '&') && nbr != 0)
		nbr--;
	if (nbr > 0)
	{
		ft_add_preci(nbr, opt, str);
		return (1);
	}
	return (0);
}
