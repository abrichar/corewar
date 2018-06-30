/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:54:32 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 14:25:43 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		ft_check_arg_opt(char **av, int ac, int i)
{
	if (ft_strstr("1234", av[i + 1]) && i + 1 < ac && !ft_strstr(av[i + 1],
	".cor") && i + 2 < ac && ft_strstr(av[i + 2], ".cor"))
	{
		return (1);
	}
	return (0);
}

int		ft_get_player_opt(t_header *header, int argc, char **argv)
{
	int			i;
	t_header	*header_last;
	int			nbr_check_player;

	i = 1;
	header_last = header;
	nbr_check_player = 0;
	while (i < argc)
	{
		if (ft_strstr(argv[i], "-n"))
		{
			if (ft_check_arg_opt(argv, argc, i))
			{
				if (ft_is_exist(header_last, ft_atoi(argv[i + 1])) != -1)
					ft_is_exist_2(&header, argv, &i, &nbr_check_player);
				else
					return (ft_is_not_exist(nbr_check_player));
			}
			else
				i++;
		}
		else
			i++;
	}
	return (nbr_check_player);
}

int		ft_get_noopt(t_header *h, int argc, char **argv, t_param *param)
{
	int			i;
	t_header	*h_last;
	int			nbr_check_player;

	i = 1;
	h_last = h;
	nbr_check_player = 0;
	while (i < argc)
	{
		h = h_last;
		while (h != NULL && h->prev != NULL && h->num_player != 0)
			h = h->prev;
		if ((ft_strstr(argv[i], ".cor") && (ft_strstr(argv[i - 1], "cor")
		|| ft_strstr(argv[i - 1], "-V"))) || (i > 2 && ft_strstr(argv[i - 2],
		"-dump") && ft_strstr(argv[i], ".cor")))
		{
			h->num_player = ft_check_number_player(h_last, param);
			h->pos_param = i;
			h = h->prev;
			nbr_check_player++;
		}
		i++;
	}
	return (nbr_check_player);
}

void	ft_init_header_list(t_param *pm, t_header **h, t_header *h_iter)
{
	int i;

	i = 1;
	while (i < pm->nb_player)
	{
		(h_iter)->prev = ft_create_new_header(h_iter);
		*h = (h_iter)->prev;
		h_iter = (h_iter)->prev;
		i++;
	}
}

int		ft_nb_player(t_param *param, t_header **header)
{
	int			i;
	int			check_arg;
	int			max_player;
	t_header	*header_last;
	t_header	*header_iter;

	header_last = *header;
	header_iter = *header;
	param->nb_player = 0;
	max_player = 0;
	check_arg = 1;
	i = 0;
	while (++i < param->argc)
		if (ft_strstr(param->argv[i], ".cor"))
			param->nb_player++;
	ft_init_header_list(param, header, header_iter);
	header_iter = header_last;
	check_arg += (ft_get_player_opt(header_last, param->argc, param->argv) * 3);
	max_player = check_arg;
	check_arg += ft_get_noopt(header_last, param->argc, param->argv, param);
	max_player = (max_player / 3) + (check_arg - max_player);
	if (!ft_check_dump(param, &check_arg) || check_arg != param->argc || max_player > MAX_PLAYERS)
		return (0);
	return (1);
}
