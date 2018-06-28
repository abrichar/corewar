/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:34:57 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 01:02:37 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_live(t_processes *p, t_counters *c, t_header *header, t_param *pm)
{
	int				nbr_player;
	unsigned char	tmp[4];

	nbr_player = 0;
	tmp[3] = c->vm[(p->pc + 1) % MEM_SIZE];
	tmp[2] = c->vm[(p->pc + 2) % MEM_SIZE];
	tmp[1] = c->vm[(p->pc + 3) % MEM_SIZE];
	tmp[0] = c->vm[(p->pc + 4) % MEM_SIZE];
	nbr_player = *(unsigned int *)tmp;
	if (ft_exist(nbr_player, header) == 1)
	{
		c->last_live = nbr_player;
		(c->period_lives[nbr_player - 1])++;
		while (header != NULL)
		{
			if (header->num_player == nbr_player)
				break ;
			header = header->next;
		}
		if (pm->ncurse != 1)
			ft_printf_fd(1, "un processus dit que le joueur %d(%s) est en vie\n"
			, nbr_player, header->prog_name);
	}
	p->lives++;
	c->lives++;
}

void	ft_st(t_processes *p, t_counters *c)
{
	int	first;
	int	second;
	int	i;

	i = 2;
	first = ft_take_parameter(p, c, &i, 1);
	second = ft_take_parameter(p, c, &i, 2);
	if (first >= 1 && first <= REG_NUMBER && p->description[0] == REG_CODE
	&& second >= 1 && second <= REG_NUMBER && p->description[1] == REG_CODE)
	{
		(p->registers)[second - 1] = (p->registers)[first - 1];
	}
	if (p->description[0] == REG_CODE && p->description[1] == IND_CODE
	&& first >= 1 && first <= REG_NUMBER)
	{
		first = p->registers[first - 1];
		second %= IDX_MOD;
		ft_write_ind(p, c, first, second);
	}
}

void	ft_ld(t_processes *p, t_counters *c)
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
		first %= IDX_MOD;
		first = ft_read_ind(p, c, first);
		(p->registers)[second - 1] = first;
		p->carry = (first == 0) ? 1 : 0;
	}
}

void	ft_zjmp(t_processes *p, t_counters *c)
{
	int jump;

	jump = 0;
	if (p->carry == 1)
	{
		jump = ft_read_two(p, c, 1);
		p->pc = (p->pc + (jump % IDX_MOD)) % MEM_SIZE;
		p->pc = (p->pc < 0) ? MEM_SIZE + p->pc : p->pc;
	}
	else
		p->pc += (p->size_param[3] + 1);
}

void	ft_fork(t_processes *p, t_counters *c, t_header *h)
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
	p_new->lives = 0;
	ft_bzero(p_new->instruction, 5, 1);
	ft_bzero(p_new->size_param, 4, 2);
	while (i < 16)
	{
		p_new->registers[i] = tmp->registers[i];
		i++;
	}
	p_new->pc = tmp->pc + (ft_read_two(p, c, 1) % IDX_MOD) % MEM_SIZE;
	p_new->pc = (p_new->pc < 0) ? MEM_SIZE + p_new->pc : p_new->pc;
}
