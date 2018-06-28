/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:17:38 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 14:26:30 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_check_number_player(t_header *header, t_param *param)
{
	int			new_player;
	int			i;
	t_header	*header_start;

	new_player = 1;
	header_start = header;
	while (new_player <= param->nb_player)
	{
		header = header_start;
		i = 0;
		while (header)
		{
			if (new_player == header->num_player)
				break ;
			else if (i == param->nb_player - 1)
				return (new_player);
			header = header->prev;
			i++;
		}
		new_player++;
	}
	return (0);
}

int		ft_is_exist(t_header *header, int nb)
{
	while (header)
	{
		if (header->num_player == nb)
			return (-1);
		header = header->next;
	}
	return (1);
}

void	ft_is_exist_2(t_header **h, char **argv, int *i, int *nbr_check_player)
{
	(*h)->num_player = ft_atoi(argv[*i + 1]);
	(*h)->pos_param = *i + 2;
	(*nbr_check_player)++;
	*h = (*h)->prev;
	*i += 3;
}

int		ft_is_not_exist(int nbr_check_player)
{
	ft_printf_fd(2, "Usage: %s\n", USAGE);
	return (nbr_check_player);
}
