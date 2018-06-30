/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:09:52 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 20:23:52 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			ft_malloc_p_c(t_processes **p, t_counters **c)
{
	if (!(*c = (t_counters*)malloc(sizeof(t_counters))))
		return (-1);
	if (!(*p = (t_processes*)malloc(sizeof(t_processes))))
	{
		free(*c);
		return (-1);
	}
	return (1);
}

t_header	*ft_create_new_header(t_header *header)
{
	t_header *new_header;

	if (!(new_header = (t_header *)malloc(sizeof(t_header))))
		return (NULL);
	new_header->magic = 0;
	new_header->prog_name[0] = '\0';
	new_header->comment[0] = '\0';
	new_header->prog_size = 0;
	new_header->data = NULL;
	new_header->num_player = 0;
	new_header->addr_start = 0;
	new_header->pos_param = 0;
	new_header->prev = NULL;
	new_header->next = header;
	return (new_header);
}

int			ft_check_player(int fd, t_header *h)
{
	int ret_inst;

	ret_inst = 0;
	ft_check_name(fd, h);
	ft_check_nbr_inst(fd, h);
	if (h->prog_size > (MEM_SIZE / 6))
		return (0);
	if (!(h->data = (unsigned char *)malloc(sizeof(unsigned char) *
	(h->prog_size + 1))))
		return (0);
	h->data[h->prog_size] = '\0';
	ft_check_comment(fd, h);
	ret_inst = ft_check_inst(fd, h);
	if (ret_inst == -1)
		return (-1);
	else if (ret_inst == -2)
		return (-2);
	else if (ret_inst == -3)
		return (-3);
	return (1);
}

t_header	*ft_init(t_param *param, t_header **header, int ac, char **av)
{
	t_header	*header_first;

	*header = ft_create_new_header(*header);
	header_first = *header;
	param->i = 0;
	param->fd = 0;
	param->argc = ac;
	param->argv = av;
	param->dump = -1;
	param->ncurse = 0;
	return (header_first);
}

void		ft_init_color(t_counters *c)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		(c->color)[i] = 30;
		i++;
	}
}
