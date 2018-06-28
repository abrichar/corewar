/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:59:15 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 15:11:50 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_load_champ_in_vm(t_header *h, t_counters *c)
{
	int				i;
	unsigned int	size;

	i = 0;
	size = 0;
	while (h != NULL)
	{
		i = h->addr_start;
		while (size < h->prog_size)
		{
			(c->vm)[i] = (h->data)[size];
			(c->color)[i] = 30 + h->num_player;
			i++;
			size++;
		}
		h = h->next;
		size = 0;
	}
}

int		ft_init_counters(t_counters *c, t_header *header, t_param *param)
{
	c->lives = 0;
	c->cycles = 0;
	c->last_live = 0;
	c->proc_alive = 0;
	c->total_cycles = 0;
	c->non_decrementation = 0;
	c->nbr_proc = param->nb_player;
	c->cycle_to_die = CYCLE_TO_DIE;
	if (!(c->vm = (unsigned char *)malloc(sizeof(unsigned char) *
	(MEM_SIZE + 1))))
		return (-1);
	if (!(c->color = (unsigned char *)malloc(sizeof(unsigned char) *
	(MEM_SIZE + 1))))
	{
		free(c->vm);
		return (-1);
	}
	ft_bzero(c->vm, MEM_SIZE + 1, 1);
	ft_init_color(c);
	ft_load_champ_in_vm(header, c);
	ft_init_period_lives(c);
	return (1);
}

int		ft_new_process(t_processes *p, t_header *h)
{
	t_processes *new_process;

	if (!(new_process = (t_processes*)malloc(sizeof(t_processes))))
		return (-1);
	p->next = new_process;
	new_process->pc = 0;
	new_process->size = 0;
	new_process->wait = -1;
	new_process->carry = 0;
	new_process->lives = 0;
	new_process->start = p;
	new_process->player = h->num_player;
	new_process->next = NULL;
	new_process->proc_nbr = h->num_player;
	ft_bzero(new_process->registers, REG_NUMBER, 2);
	new_process->registers[0] = h->num_player;
	ft_bzero(new_process->instruction, 5, 1);
	ft_bzero(new_process->description, 3, 2);
	ft_bzero(new_process->size_param, 4, 2);
	return (1);
}

int		ft_add_process(t_processes *p, t_header *h, int proc_nbr)
{
	t_processes *new_process;
	t_processes *tmp;

	tmp = p->next;
	if (!(new_process = (t_processes*)malloc(sizeof(t_processes))))
		return (-1);
	p->next = new_process;
	new_process->pc = 0;
	new_process->size = 0;
	new_process->wait = -1;
	new_process->carry = 0;
	new_process->lives = 0;
	new_process->start = p;
	new_process->next = tmp;
	new_process->player = (proc_nbr < 5) ? h->num_player : proc_nbr;
	new_process->proc_nbr = (proc_nbr < 5) ? h->num_player : proc_nbr;
	ft_bzero(new_process->registers, REG_NUMBER, 2);
	new_process->registers[0] = h->num_player;
	ft_bzero(new_process->instruction, 5, 1);
	ft_bzero(new_process->description, 3, 2);
	ft_bzero(new_process->size_param, 4, 2);
	return (1);
}

int		ft_init_processes(t_processes *p, t_header *h)
{
	t_processes	*start_process;
	int			proc_nbr;

	start_process = p;
	p->proc_nbr = 0;
	p->next = NULL;
	proc_nbr = 1;
	p->start = p;
	while (h->next)
		h = h->next;
	if (!(ft_new_process(p, h)))
		return (-1);
	while (h != NULL)
	{
		(start_process->next)->pc = h->addr_start;
		h = h->prev;
		if (h != NULL)
		{
			proc_nbr++;
			if (ft_add_process(start_process, h, proc_nbr) == -1)
				return (-1);
		}
	}
	return (1);
}
