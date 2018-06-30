/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 00:43:54 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 00:47:22 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_show_player_x(t_header *h, t_counters *c, int *space)
{
	attron(COLOR_PAIR(30 + h->num_player));
	mvprintw(66, *space, "Player %-2d : %.30s", h->num_player, h->prog_name);
	mvprintw(67, *space, "Lives : %-10d", c->period_lives[h->num_player - 1]);
	*space += 50;
}

void	ft_show_player(t_counters *c, t_header *h, t_param *pm)
{
	t_header	*h_tmp;
	int			space;
	int			i;
	int			j;

	space = 3;
	h_tmp = h;
	i = 1;
	j = 0;
	while (j < pm->nb_player)
	{
		h = h_tmp;
		while (h)
		{
			if (h->num_player == i)
			{
				ft_show_player_x(h, c, &space);
				j++;
			}
			h = h->next;
		}
		i++;
	}
}

void	ft_show_info_vm(t_counters *c)
{
	attron(COLOR_PAIR(30));
	mvprintw(71, 3, "CYCLE : %-30d  CYCLE_TO_DIE : %-30d ",
	c->total_cycles + 1, c->cycle_to_die);
	printw("MAX_CHECKS : %-30d", MAX_CHECKS - c->non_decrementation);
	printw("LAST LIVE : player %-30d", c->last_live);
	printw("LIVE : %d", c->lives);
}

void	ft_color_pc(t_counters *c, t_processes *p, int mode)
{
	t_processes *p_iter;

	p_iter = p;
	if (mode == 1)
	{
		while (p_iter)
		{
			if (c->color[p_iter->pc] < 39)
				c->color[p_iter->pc] += 10;
			p_iter = p_iter->next;
		}
	}
	else
	{
		while (p_iter)
		{
			if (c->color[p_iter->pc] > 39)
				c->color[p_iter->pc] -= 10;
			p_iter = p_iter->next;
		}
	}
}

void	ft_init_color_pc(t_counters *c, t_processes *p)
{
	start_color();
	init_color(COLOR_WHITE, 400, 400, 400);
	init_pair(30, COLOR_WHITE, COLOR_BLACK);
	init_pair(31, COLOR_RED, COLOR_BLACK);
	init_pair(32, COLOR_GREEN, COLOR_BLACK);
	init_pair(33, COLOR_YELLOW, COLOR_BLACK);
	init_pair(34, COLOR_BLUE, COLOR_BLACK);
	init_pair(40, COLOR_BLACK, COLOR_WHITE);
	init_pair(41, COLOR_WHITE, COLOR_RED);
	init_pair(42, COLOR_WHITE, COLOR_GREEN);
	init_pair(43, COLOR_WHITE, COLOR_YELLOW);
	init_pair(44, COLOR_WHITE, COLOR_BLUE);
	ft_color_pc(c, p, 1);
	attron(COLOR_PAIR(31));
	mvprintw(0, 75, "[ %s ]", TITLE);
}
