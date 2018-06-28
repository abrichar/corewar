/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_instruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 01:31:58 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 01:34:51 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_get_ocp(t_processes *p, t_counters *c, int op, int bin)
{
	static int i = 0;

	if (p->wait == -2)
		i = 0;
	if (((c->vm[p->pc + 1 % MEM_SIZE] >> bin) & 0b11) == REG_CODE)
	{
		p->size_param[i] = REG_SIZE;
		p->description[i] = REG_CODE;
	}
	else if (((c->vm[p->pc + 1 % MEM_SIZE] >> bin) & 0b11) == IND_CODE)
	{
		p->size_param[i] = IND_SIZE;
		p->description[i] = IND_CODE;
	}
	else if (((c->vm[p->pc + 1 % MEM_SIZE] >> bin) & 0b11) == DIR_CODE)
	{
		p->size_param[i] = (g_op_tab[op].short_dir == 1) ? IND_SIZE : DIR_SIZE;
		p->description[i] = DIR_CODE;
	}
	p->wait = 0;
	i++;
}

void	ft_check_ocp(t_processes *p, t_counters *c, int op)
{
	int i;

	i = 0;
	ft_bzero(p->description, 3, 2);
	ft_bzero(p->size_param, 4, 2);
	ft_get_ocp(p, c, op, 6);
	if (g_op_tab[op].nb_params > 1)
		ft_get_ocp(p, c, op, 4);
	if (g_op_tab[op].nb_params > 2)
		ft_get_ocp(p, c, op, 2);
	while (i < 3)
	{
		p->size_param[3] += p->size_param[i];
		i++;
	}
}

int		ft_instruct_parse(t_processes *p, t_counters *c, int op)
{
	if (c->vm[p->pc] == g_op_tab[op].opcode)
	{
		if (g_op_tab[op].ocp == 1)
		{
			ft_check_ocp(p, c, op);
			return (p->size_param[3] + 1);
		}
		else if (g_op_tab[op].nb_params == 1 && g_op_tab[op].
		params_type[0] != 1 && g_op_tab[op].short_dir != 1)
		{
			p->size_param[3] = DIR_SIZE;
			return (DIR_SIZE);
		}
		else if ((g_op_tab[op].nb_params == 1 && g_op_tab[op].
		params_type[0] != 1 && g_op_tab[op].short_dir == 1) ||
		(g_op_tab[op].nb_params == 1 && g_op_tab[op].
		params_type[0] == 1) || (ft_strncmp(g_op_tab[op].name,
		"zjmp", 4) == 0))
		{
			p->size_param[3] = IND_SIZE;
			return (IND_SIZE);
		}
	}
	return (0);
}
