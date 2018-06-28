/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:52:55 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 16:07:19 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_addr_start_2(t_param *param, int check)
{
	if (check == 0)
		return (0);
	if (param->nb_player == 2)
	{
		if (check == 1)
			return (2048);
	}
	if (param->nb_player == 3)
	{
		if (check == 1)
			return (1365);
		if (check == 2)
			return (2730);
	}
	if (param->nb_player == 4)
	{
		if (check == 1)
			return (1024);
		if (check == 2)
			return (2048);
		if (check == 3)
			return (3072);
	}
	return (0);
}

void	ft_addr_start(t_param *param, t_header *header)
{
	int			num;
	t_header	*start;
	int			check;

	num = 1;
	start = header;
	check = 0;
	while (check < param->nb_player)
	{
		if (header->num_player == num)
		{
			header->addr_start = ft_addr_start_2(param, check);
			check++;
			num++;
			header = start;
		}
		else
			header = header->next;
		if (header == NULL)
		{
			header = start;
			num++;
		}
	}
	header = start;
}
