/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 00:12:17 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 00:44:48 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_printw_memory(t_counters *c)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		attron(COLOR_PAIR(c->color[i]));
		if ((i % 64) == 0)
			mvprintw(i / 64 + 1, 3 + ((i % 64) * 3), "%02x", c->vm[i]);
		else
			mvprintw(i / 64 + 1, (i % 64) * 3 + 3, "%02x", c->vm[i]);
		i++;
	}
}

void	ft_speed(int key, int *speed, int *delay)
{
	if (key == KEY_UP && *speed < 100 && *speed >= 0)
	{
		*delay -= 1000;
		*speed += 1;
		mvprintw(73, 3, "Speed : %03d %%", *speed);
	}
	else if (key == KEY_DOWN && *speed <= 100 && *speed > 0)
	{
		*speed -= 1;
		mvprintw(73, 3, "Speed : %03d %%", *speed);
		*delay += 1000;
		if (*delay < 0)
			*delay = 0;
	}
}

void	ft_pause(int key, int *speed, int *delay, t_counters *c)
{
	static int step = 0;

	if (key == KEY_LEFT || c->total_cycles == 0 || step == 1)
	{
		step = 1;
		while (1)
		{
			key = getch();
			if (key == KEY_RIGHT)
			{
				step = 0;
				break ;
			}
			else if (key == 32)
				break;
			else if (key == KEY_UP || key == KEY_DOWN)
				ft_speed(key, speed, delay);
		}
	}
}

void	ft_delay(int key, int *speed, int *delay, t_counters *c)
{
	int i;

	i = 0;
	while (i <= *delay)
	{
		key = getch();
		ft_speed(key, speed, delay);
		if (key == KEY_LEFT)
			ft_pause(key, speed, delay, c);
		else if (key == 32)
			break;
		if (key != 32)
			usleep(1);
		i++;
	}
}

void	ft_ncurse(t_counters *c, t_processes *p, t_param *param, t_header *h)
{
	int			key;
	static int	delay = 50000;
	static int	speed = 50;

	WINDOW * boite;
	key = 0;
	boite = subwin(stdscr, 75, 197, 0, 0);
	keypad(stdscr, TRUE);
	curs_set(0);
	ft_init_color_pc(c, p);
	box(boite, ACS_VLINE, ACS_HLINE);
	nodelay(stdscr, TRUE);
	ft_printw_memory(c);
	ft_show_player(c, h, param);
	ft_show_info_vm(c);
	ft_color_pc(c, p, 0);
	key = getch();
	ft_pause(key, &speed, &delay, c);
	ft_speed(key, &speed, &delay);
	ft_delay(key, &speed, &delay, c);
	refresh();
}
