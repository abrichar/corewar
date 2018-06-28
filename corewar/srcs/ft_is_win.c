/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 00:30:06 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 00:37:40 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_at_least_one_process(t_processes *p)
{
	while (p != NULL)
	{
		if (p->proc_nbr > 0)
			return (1);
		p = p->next;
	}
	return (0);
}

void	ft_there_is_win(t_param *pm, t_header *h, t_counters *c)
{
	int key;

	key = 0;
	if (pm->ncurse == 1)
	{
		mvprintw(73, 43, "Le joueur ");
		attron(COLOR_PAIR(30 + h->num_player));
		printw("%d (%s)", c->last_live, h->prog_name);
		attron(COLOR_PAIR(30));
		printw(" a gagne !");
		refresh();
		while (1)
		{
			key = getch();
			if (key == KEY_RIGHT)
				break ;
		}
		endwin();
	}
	else
	{
		ft_printf_fd(1, "Le joueur %d(%s) a gagne !\n",
		c->last_live, h->prog_name);
	}
}

void	ft_there_isnt_win(t_param *pm)
{
	int key;

	key = 0;
	if (pm->ncurse == 1)
	{
		attron(COLOR_PAIR(31));
		mvprintw(73, 43, "Ouups ! Il n'y a pas de gagnant...");
		refresh();
		while (1)
		{
			key = getch();
			if (key == KEY_RIGHT)
				break ;
		}
		endwin();
	}
	else
		ft_printf_fd(1, "Ouups ! Il n'y a pas de gagnant...\n");
}

void	ft_show_winner(t_counters *c, t_header *header, t_param *param)
{
	int key;

	key = 0;
	while (header != NULL)
	{
		if (header->num_player == c->last_live)
			break ;
		header = header->next;
	}
	if (c->last_live != 0)
		ft_there_is_win(param, header, c);
	else
		ft_there_isnt_win(param);
}
