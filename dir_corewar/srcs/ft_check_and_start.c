/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:12:21 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 22:20:06 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_usage(void)
{
	ft_printf_fd(2, "Usage : %s\n", USAGE);
	ft_printf_fd(2, "-dump : shows N-cycle memory\n");
	ft_printf_fd(2, "-V    : Ncurses mode\n");
	ft_printf_fd(2, "      : %C for speed up\n", L'↑');
	ft_printf_fd(2, "      : %C for speed down\n", L'↓');
	ft_printf_fd(2, "      : %C for game start\n", L'→');
	ft_printf_fd(2, "      : %C for game pause\n", L'←');
	ft_printf_fd(2, "      : ' ' for step by step\n");
}

void		ft_init_period_lives(t_counters *c)
{
	int i;

	i = 0;
	while (i <= 3)
	{
		c->period_lives[i] = 0;
		i++;
	}
}

static void	ft_show_error(int check_valid_player)
{
	if (check_valid_player == 0)
		ft_printf_fd(2, "Error: the memory allocation  has failed.\n");
	else if (check_valid_player == -1)
		ft_printf_fd(2, "Error: the file has too much instruction.\n");
	else if (check_valid_player == -2)
		ft_printf_fd(2, "Error: the file is not enough instruction.\n");
	else if (check_valid_player == -3)
		ft_printf_fd(2, "Error: the file has an unauthorized change.\n");
}

static int	ft_read_champ(t_param *pm, t_header *h, char **argv)
{
	int			check_valid_player;

	while (pm->i < pm->nb_player)
	{
		pm->fd = open(argv[h->pos_param], O_RDONLY);
		if (ft_check_magic(pm->fd, h))
		{
			check_valid_player = ft_check_player(pm->fd, h);
			ft_show_error(check_valid_player);
			if (check_valid_player < 1)
				close(pm->fd);
			if (check_valid_player < 1)
				break ;
		}
		else
		{
			ft_printf_fd(2, "%s is not valid file.\n", pm->argv[h->pos_param]);
			close(pm->fd);
			return (0);
		}
		close(pm->fd);
		pm->i++;
		h = h->next;
	}
	return ((check_valid_player < 1) ? 0 : 1);
}

int			ft_start(t_processes *p, t_header *h, t_param *pm, t_counters *c)
{
	t_header	*header_first;

	header_first = NULL;
	header_first = ft_init(pm, &h, pm->argc, pm->argv);
	if (!ft_nb_player(pm, &h))
	{
		ft_printf_fd(2, "Usage: %s\n", USAGE);
		return (-1);
	}
	if (pm->nb_player == 0)
	{
		ft_usage();
		return (-1);
	}
	if (header_first == NULL)
		return (-1);
	if (ft_read_champ(pm, h, pm->argv) == 1)
	{
		if (ft_init_vm(&p, &c, h, pm) == -1)
			return (-1);
		ft_vm(p, c, pm, h);
		ft_free(header_first);
	}
	return (1);
}
