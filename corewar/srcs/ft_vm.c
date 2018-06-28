/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:40:53 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 15:18:59 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_check_lives2(t_processes *p_start, t_counters *c)
{
	t_processes *p;
	t_processes *tmp;

	p = p_start;
	tmp = NULL;
	if (p->next && p->next->lives == 0)
	{
		ft_check_lives2(p->next, c);
		tmp = p->next->next;
		free(p->next);
		p->next = tmp;
	}
	if (p->lives != 0 && p->proc_nbr != 0)
		p->lives = 0;
}

void	ft_check_lives(t_processes *p_start, t_counters *c)
{
	t_processes *p;

	p = p_start;
	while (p)
	{
		ft_check_lives2(p, c);
		p = p->next;
	}
}

int		ft_init_vm(t_processes **p, t_counters **c, t_header *h, t_param *pm)
{
	if (ft_malloc_p_c(p, c) == -1)
		return (-1);
	ft_addr_start(pm, h);
	if (ft_init_processes(*p, h) == -1
	|| ft_init_counters(*c, h, pm) == -1)
	{
		ft_medium_free(*p, *c, h);
		return (-1);
	}
	return (1);
}

void	ft_cycle_to_die(t_counters *c)
{
	int		i;

	i = 0;
	if (c->lives >= NBR_LIVE)
	{
		c->cycle_to_die -= CYCLE_DELTA;
		c->non_decrementation = 0;
	}
	else
	{
		c->non_decrementation++;
		if (c->non_decrementation == MAX_CHECKS)
		{
			c->cycle_to_die -= CYCLE_DELTA;
			c->non_decrementation = 0;
		}
	}
	c->lives = 0;
	c->cycles = 0;
	while (i <= 3)
	{
		c->period_lives[i] = 0;
		i++;
	}
}

void	ft_vm(t_processes *p, t_counters *c, t_param *pm, t_header *h)
{
	if (pm->ncurse == 1)
		initscr();
	while (ft_at_least_one_process(p) == 1 && c->cycle_to_die >= 0)
	{
		ft_process(p, c, pm, h);
		if (pm->dump == 0 && pm->ncurse == 1)
			ft_ncurse(c, p->next, pm, h);
		if ((c->cycles % c->cycle_to_die) == 0 && c->cycles != 0)
		{
			ft_check_lives(p, c);
			ft_cycle_to_die(c);
		}
		c->cycles++;
		c->total_cycles++;
		if (c->total_cycles == pm->dump)
		{
			endwin();
			pm->ncurse = 0;
			ft_dump(c, p);
			return ;
		}
	}
	ft_show_winner(c, h, pm);
}
