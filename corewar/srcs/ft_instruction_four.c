/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_four.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:31:27 by mpascaud          #+#    #+#             */
/*   Updated: 2018/06/28 00:55:05 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_lld(t_processes *p, t_counters *c)
{
	unsigned int	first;
	unsigned int	second;
	int				i;

	i = 2;
	first = ft_take_parameter(p, c, &i, 1);
	second = ft_take_parameter(p, c, &i, 2);
	if (p->description[0] == DIR_CODE && p->description[1] == REG_CODE
			&& second >= 1 && second <= REG_NUMBER)
	{
		(p->registers)[second - 1] = first;
		p->carry = (first == 0) ? 1 : 0;
	}
	if (p->description[0] == IND_CODE && p->description[1] == REG_CODE
			&& second >= 1 && second <= REG_NUMBER)
	{
		first = ft_read_ind(p, c, first);
		(p->registers)[second - 1] = first;
		p->carry = (first == 0) ? 1 : 0;
	}
}

void	ft_lldi(t_processes *p, t_counters *c)
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
		first = ft_read_ind(p, c, first);
	second = (p->description[1] == 1) ? p->registers[second - 1] : second;
	address = first + second;
	address = ft_read_ind(p, c, address);
	p->carry = (address == 0) ? 1 : 0;
	p->registers[third - 1] = address;
}
