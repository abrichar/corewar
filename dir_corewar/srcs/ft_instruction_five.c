/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:05:49 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 18:03:00 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_val_reg(int nb)
{
	return ((nb > 0 && nb < 17));
}

int		ft_get_arg(t_processes *p, t_counters *c, int arg, int num_arg)
{
	if (p->description[num_arg - 1] == REG_CODE)
	{
		if (!ft_val_reg(arg))
			return (-1);
		arg = p->registers[arg - 1];
	}
	else if (p->description[num_arg - 1] == IND_CODE)
		arg = ft_read_ind(p, c, arg);
	return (arg);
}

void	ft_lfork(t_processes *p, t_counters *c, t_header *h)
{
	t_processes	*tmp;
	t_processes	*p_new;
	t_processes	*start;
	int			i;

	i = 0;
	tmp = p;
	start = p->start;
	ft_add_process(start, h, 0);
	p_new = start->next;
	p_new->player = tmp->player;
	c->nbr_proc++;
	p_new->proc_nbr = c->nbr_proc;
	p_new->carry = tmp->carry;
	p_new->lives = tmp->lives;
	ft_bzero(p_new->instruction, 5, 1);
	ft_bzero(p_new->size_param, 4, 2);
	while (p_new->registers[i])
	{
		p_new->registers[i] = tmp->registers[i];
		i++;
	}
	p_new->pc = (tmp->pc + ft_read_two(p, c, 1)) % MEM_SIZE;
	p_new->pc = (p_new->pc < 0) ? MEM_SIZE + p_new->pc : p_new->pc;
}

void	ft_aff(t_processes *p, t_counters *c, t_header *h, t_param *pm)
{
	unsigned int	first;
	int				i;

	i = 2;
	if (p->description[0] == REG_CODE)
	{
		first = ft_take_parameter(p, c, &i, 1);
		if (!ft_val_reg(first))
			return ;
		if (pm->ncurse != 1)
			ft_printf_fd(1, "%s say : %C\n", h->prog_name,
			p->registers[first - 1] % 256);
	}
}
