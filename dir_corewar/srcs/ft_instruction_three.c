/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:48:33 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 00:56:28 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_add(t_processes *p, t_counters *c)
{
	int	one;
	int	two;
	int	three;
	int	i;

	i = 2;
	if (p->description[0] == REG_CODE && p->description[1] == REG_CODE &&
		p->description[2] == REG_CODE)
	{
		one = ft_take_parameter(p, c, &i, 1);
		two = ft_take_parameter(p, c, &i, 2);
		three = ft_take_parameter(p, c, &i, 3);
		if (!ft_val_reg(one) || !ft_val_reg(two) || !ft_val_reg(three))
			return ;
		p->registers[three - 1] = p->registers[one - 1] + p->registers[two - 1];
		p->carry = (p->registers[three - 1] == 0) ? 1 : 0;
	}
}

void	ft_sub(t_processes *p, t_counters *c)
{
	int	one;
	int	two;
	int	three;
	int	i;

	i = 2;
	if (p->description[0] == REG_CODE && p->description[1] == REG_CODE &&
		p->description[2] == REG_CODE)
	{
		one = ft_take_parameter(p, c, &i, 1);
		two = ft_take_parameter(p, c, &i, 2);
		three = ft_take_parameter(p, c, &i, 3);
		if (!ft_val_reg(one) || !ft_val_reg(two) || !ft_val_reg(three))
			return ;
		p->registers[three - 1] = p->registers[one - 1] - p->registers[two - 1];
		p->carry = (p->registers[three - 1] == 0) ? 1 : 0;
	}
}

void	ft_and(t_processes *p, t_counters *c)
{
	int	one;
	int	two;
	int	three;
	int	i;

	i = 2;
	if ((p->description[0] != NUL_CODE && p->description[1] != NUL_CODE &&
		p->description[2] == REG_CODE))
	{
		one = ft_take_parameter(p, c, &i, 1);
		two = ft_take_parameter(p, c, &i, 2);
		three = ft_take_parameter(p, c, &i, 3);
		if (!ft_val_reg(three))
			return ;
		one = ft_get_arg(p, c, one, 1);
		two = ft_get_arg(p, c, two, 2);
		if (one == -1 || two == -1)
			return ;
		p->registers[three - 1] = one & two;
		p->carry = (p->registers[three - 1] == 0) ? 1 : 0;
	}
}

void	ft_or(t_processes *p, t_counters *c)
{
	int	one;
	int	two;
	int	three;
	int	i;

	i = 2;
	if ((p->description[0] != NUL_CODE && p->description[1] != NUL_CODE &&
		p->description[2] == REG_CODE))
	{
		one = ft_take_parameter(p, c, &i, 1);
		two = ft_take_parameter(p, c, &i, 2);
		three = ft_take_parameter(p, c, &i, 3);
		if (!ft_val_reg(three))
			return ;
		one = ft_get_arg(p, c, one, 1);
		two = ft_get_arg(p, c, two, 2);
		if (one == -1 || two == -1)
			return ;
		p->registers[three - 1] = one | two;
		p->carry = (p->registers[three - 1] == 0) ? 1 : 0;
	}
}

void	ft_xor(t_processes *p, t_counters *c)
{
	int	one;
	int	two;
	int	three;
	int	i;

	i = 2;
	if ((p->description[0] != NUL_CODE && p->description[1] != NUL_CODE &&
		p->description[2] == REG_CODE))
	{
		one = ft_take_parameter(p, c, &i, 1);
		two = ft_take_parameter(p, c, &i, 2);
		three = ft_take_parameter(p, c, &i, 3);
		if (!ft_val_reg(three))
			return ;
		one = ft_get_arg(p, c, one, 1);
		two = ft_get_arg(p, c, two, 2);
		if (one == -1 || two == -1)
			return ;
		p->registers[three - 1] = one ^ two;
		p->carry = (p->registers[three - 1] == 0) ? 1 : 0;
	}
}
