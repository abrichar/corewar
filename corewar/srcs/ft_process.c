/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_instruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 22:18:23 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 17:49:51 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	ft_get_op(t_processes *p, t_counters *c, t_header *h, t_param *pm)
{
	int i;
	int size;

	i = -1;
	size = 0;
	while (++i < 16)
	{
		if (c->vm[p->pc] == g_op_tab[i].opcode && p->wait == -1)
		{
			p->wait = g_op_tab[i].cycles - 1;
			ft_strcpy(p->instruction, g_op_tab[i].name);
			break ;
		}
		else if (c->vm[p->pc] == g_op_tab[i].opcode && p->wait == 0)
		{
			p->wait = -2;
			size = ft_instruct_parse(p, c, g_op_tab[i].opcode - 1);
			(g_op_tab[i].opcode == 1 || g_op_tab[i].opcode == 16) ?
			g_op_tab[i].fonction(p, c, h, pm) : g_op_tab[i].fonction(p, c, h);
			p->pc += (i != 8) ? (size + 1) : 0;
			p->wait = -1;
			break ;
		}
	}
}

static void	ft_check_op(t_processes *p, t_counters *c, t_header *h, t_param *pm)
{
	while (p)
	{
		p->pc %= MEM_SIZE;
		ft_get_op(p, c, h, pm);
		p = p->next;
	}
}

static void	ft_decrement_wait(t_processes *p, t_counters *c)
{
	int		i;

	while (p)
	{
		p->pc = p->pc % 4096;
		i = 0;
		if (p->wait > 0)
			p->wait = p->wait - 1;
		while (i < 16)
		{
			p->pc %= MEM_SIZE;
			if (i == (16 - 1) && c->vm[p->pc % MEM_SIZE] != g_op_tab[i].opcode)
				p->pc = (p->pc + 1) % MEM_SIZE;
			else if (c->vm[p->pc % MEM_SIZE] == g_op_tab[i].opcode)
				break ;
			i++;
		}
		p = p->next;
	}
}

void		ft_process(t_processes *p, t_counters *c, t_param *pm, t_header *h)
{
	t_processes	*p_start;

	p = p->next;
	p_start = p;
	ft_check_op(p, c, h, pm);
	ft_decrement_wait(p_start, c);
}
