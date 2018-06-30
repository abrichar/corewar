/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:29:30 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 14:16:48 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	*ft_get_pc(t_processes *p, t_counters *c)
{
	int			*tab_pc;
	t_processes	*p_start;
	int			i;

	p_start = p;
	c->proc_alive = 0;
	while (p)
	{
		c->proc_alive++;
		p = p->next;
	}
	if (!(tab_pc = malloc(sizeof(int) * (c->proc_alive + 1))))
		return (NULL);
	tab_pc[c->proc_alive] = 0;
	ft_bzero(tab_pc, c->proc_alive, 2);
	i = 0;
	p = p_start;
	while (p)
	{
		tab_pc[i] = p->pc % MEM_SIZE;
		p = p->next;
		i++;
	}
	return (tab_pc);
}

static void	ft_color_vm(t_counters *c, t_processes *p, int *tab_pc)
{
	int			i;
	int			j;
	t_processes	*p_start;

	i = 0;
	p_start = p;
	while (i < MEM_SIZE)
	{
		j = 0;
		c->color[i] = (c->color[i] == 40) ? 30 : c->color[i];
		while (j < c->proc_alive)
		{
			if (tab_pc[j] == i && c->vm[i] != 0)
			{
				p = p_start;
				while (p->pc != tab_pc[j] && p->next != NULL)
					p = p->next;
				c->color[i] = 30 + p->player + 10;
			}
			else if (c->vm[i] == 0 && i == tab_pc[j])
				c->color[i] = 40;
			j++;
		}
		i++;
	}
}

static void	ft_uncolor_vm(t_counters *c, t_processes *p, int *tab_pc)
{
	int			i;
	int			j;
	t_processes	*p_start;

	p_start = p;
	i = 0;
	while (i < MEM_SIZE)
	{
		j = 0;
		while (j < c->proc_alive)
		{
			if (tab_pc[j] == i)
			{
				if (c->vm[i] != 0)
					c->color[i] -= 10;
				if (p_start->next != NULL)
					p_start = p_start->next;
			}
			j++;
		}
		i++;
	}
}

int			ft_check_dump(t_param *pm, int *check_arg)
{
	int i;

	i = 1;
	while (i < pm->argc)
	{
		if (ft_strstr(pm->argv[i], "-dump") && i + 1 < pm->argc &&
		ft_isdigit(pm->argv[i + 1][0]))
		{
			pm->dump = ft_atoi(pm->argv[i + 1]) - 1;
			pm->dump = (pm->dump < 0) ? 0 : pm->dump;
			*check_arg += 2;
		}
		else if (ft_strstr(pm->argv[i], "-dump") && i + 1 >= pm->argc)
			return (0);
		if (ft_strstr(pm->argv[i], "-V"))
		{
			pm->ncurse = (pm->dump != 1) ? 1 : 0;
			*check_arg += 1;
		}
		i++;
	}
	return (1);
}

void		ft_dump(t_counters *c, t_processes *p)
{
	int *tab_pc;
	int i;
	int j;

	i = 0;
	j = 0;
	tab_pc = ft_get_pc(p, c);
	ft_color_vm(c, p, tab_pc);
	ft_printf_fd(1, "\033[47;01m%27c\033[00m\033[47;37;01m%s\033[00m",
	' ', TITLE);
	ft_printf_fd(1, "\033[47;37;05m%26c\033[00m\n", ' ');
	ft_printf_fd(1, "\033[47;37;05m \033[00m ");
	while (i < MEM_SIZE && c->total_cycles >= 0)
	{
		ft_printf_fd(1, "\033[%d;01m%02x\033[00m ", c->color[i], c->vm[i]);
		if (i % 32 == 31 & i != 0)
		{
			ft_printf_fd(1, "\033[47;37;05m \033[00m\n");
			(i > 4090) ? ft_printf_fd(1, "\033[47;37;05m  \033[00m") :
				ft_printf_fd(1, "\033[47;37;05m \033[00m ");
		}
		i++;
	}
	ft_printf_fd(1, "\033[47;37;05m%97c\033[00m\n", ' ');
	ft_uncolor_vm(c, p, tab_pc);
}
