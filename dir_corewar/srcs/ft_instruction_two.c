/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 23:57:28 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 02:06:53 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_invalid_sti(t_processes *p, int first, int second, int third)
{
	if ((!(first >= 1 && first <= REG_NUMBER && p->description[0] == 1))
			|| (p->description[1] < 1 || p->description[1] > 3)
			|| (p->description[1] == 1 && (second < 1 || second > REG_NUMBER))
			|| (p->description[2] == 1 && (third < 1 || third > REG_NUMBER))
			|| (p->description[2] != 1 && p->description[2] != 2))
		return (1);
	return (0);
}

int			ft_invalid_ldi(t_processes *p, int first, int second, int third)
{
	if ((p->description[0] == 1 && (first < 1 || first > REG_NUMBER))
			|| (p->description[0] == 0)
			|| (p->description[1] == 1 && (second < 1 || second > REG_NUMBER))
			|| (p->description[1] == 0 || p->description[1] == 3)
			|| (p->description[2] == 1 && (third < 1 || third > REG_NUMBER))
			|| (p->description[2] != 1))
		return (1);
	return (0);
}

void		ft_ldi(t_processes *p, t_counters *c)
{
	int		first;
	int		second;
	int		third;
	int		i;
	int		address;

	i = 2;
	address = 0;
	first = ft_take_parameter(p, c, &i, 1);
	second = ft_take_parameter(p, c, &i, 2);
	third = ft_take_parameter(p, c, &i, 3);
	if (ft_invalid_ldi(p, first, second, third) == 1)
		return ;
	first = (p->description[0] == 1) ? p->registers[first - 1] : first;
	if (p->description[0] == 3)
	{
		first %= IDX_MOD;
		first = ft_read_ind(p, c, first);
	}
	second = (p->description[1] == 1) ? p->registers[second - 1] : second;
	address = first + second;
	address %= IDX_MOD;
	address = ft_read_ind(p, c, address);
	p->registers[third - 1] = address;
}

void		ft_sti(t_processes *p, t_counters *c)
{
	int		first;
	int		second;
	int		third;
	int		i;
	int		address;

	i = 2;
	first = ft_take_parameter(p, c, &i, 1);
	second = ft_take_parameter(p, c, &i, 2);
	third = ft_take_parameter(p, c, &i, 3);
	if (ft_invalid_sti(p, first, second, third) == 1)
		return ;
	first = p->registers[first - 1];
	if (p->description[1] == 1)
		second = p->registers[second - 1];
	if (p->description[1] == 3)
	{
		second %= IDX_MOD;
		second = ft_read_ind(p, c, second);
	}
	if (p->description[2] == 1)
		third = p->registers[third - 1];
	address = second + third;
	address %= IDX_MOD;
	ft_write_ind(p, c, first, address);
}
