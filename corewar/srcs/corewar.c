/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:46:43 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 21:27:21 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		main(int argc, char **argv)
{
	t_header	*h;
	t_param		pm;
	t_counters	*c;
	t_processes *p;

	h = NULL;
	p = NULL;
	c = NULL;
	pm.argc = argc;
	pm.argv = argv;
	if (ft_start(p, h, &pm, c) == -1)
		return (-1);
	ft_final_free(p, c);
	return (0);
}
