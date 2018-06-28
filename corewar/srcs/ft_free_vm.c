/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:20:00 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 16:44:57 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_final_free(t_processes *p, t_counters *c)
{
	t_processes	*p_tmp;

	if (c)
	{
		free(c->vm);
		free(c->color);
		free(c);
	}
	while (p != NULL)
	{
		p_tmp = p->next;
		free(p);
		p = p_tmp;
	}
}

void	ft_medium_free(t_processes *p, t_counters *c, t_header *header_first)
{
	t_processes	*p_tmp;

	while (p != NULL)
	{
		p = p_tmp->next;
		free(p_tmp);
		p_tmp = p;
	}
	free(p_tmp);
	ft_free(header_first);
	free(c);
}

void	ft_free(t_header *header)
{
	t_header *header_tmp;

	header_tmp = NULL;
	while (header)
	{
		header_tmp = header->prev;
		free(header->data);
		free(header);
		header = header_tmp;
	}
	free(header);
}
