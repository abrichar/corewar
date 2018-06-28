/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:09:46 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 01:06:04 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_exist(int nbr_player, t_header *header)
{
	while (header != NULL)
	{
		if (header->num_player == nbr_player)
			return (1);
		header = header->next;
	}
	return (0);
}

int		ft_take_parameter(t_processes *p, t_counters *c, int *i, int n)
{
	unsigned int	result;
	int				size;
	char			*tmp;
	int				begin;

	size = p->size_param[n - 1];
	if (!(tmp = (char*)malloc(sizeof(char) * (size))))
		return (-1);
	begin = *i;
	size--;
	while (size >= 0)
	{
		tmp[size] = c->vm[(p->pc + *i) % MEM_SIZE];
		(*i) += 1;
		size--;
	}
	if (*i - begin == 4)
		result = *(int*)tmp;
	if (*i - begin == 2)
		result = *(short int*)tmp;
	if (*i - begin == 1)
		result = *(char*)tmp;
	free(tmp);
	return (result);
}

int		ft_read_ind(t_processes *p, t_counters *c, unsigned int first)
{
	int				ind;
	unsigned char	tmp[4];

	ind = 0;
	tmp[3] = c->vm[(p->pc + first) % MEM_SIZE];
	tmp[2] = c->vm[(p->pc + first + 1) % MEM_SIZE];
	tmp[1] = c->vm[(p->pc + first + 2) % MEM_SIZE];
	tmp[0] = c->vm[(p->pc + first + 3) % MEM_SIZE];
	ind = *(int*)tmp;
	return (ind);
}

int		ft_read_two(t_processes *p, t_counters *c, unsigned int first)
{
	short int		ind;
	unsigned char	tmp[2];

	ind = 0;
	tmp[1] = c->vm[(p->pc + first) % MEM_SIZE];
	tmp[0] = c->vm[(p->pc + first + 1) % MEM_SIZE];
	ind = *(short int*)tmp;
	return (ind);
}

void	ft_write_ind(t_processes *p, t_counters *c, int one, int two)
{
	int		positive;

	positive = p->pc + two;
	positive = (positive < 0) ? MEM_SIZE + positive : positive;
	c->vm[positive % MEM_SIZE] = (one >> 24) & 0b11111111;
	c->color[positive % MEM_SIZE] = p->player + 30;
	c->vm[(positive + 1) % MEM_SIZE] = (one >> 16) & 0b11111111;
	c->color[(positive + 1) % MEM_SIZE] = p->player + 30;
	c->vm[(positive + 2) % MEM_SIZE] = (one >> 8) & 0b11111111;
	c->color[(positive + 2) % MEM_SIZE] = p->player + 30;
	c->vm[(positive + 3) % MEM_SIZE] = one & 0b11111111;
	c->color[(positive + 3) % MEM_SIZE] = p->player + 30;
}
