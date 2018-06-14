/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 19:16:18 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/05 23:02:22 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#include "../libft/libft.h"
#include "../libft/ft_printf.h"
#include "op.h"


typedef struct  s_processes
{
	int     player;
	int     reading;//utile ?
	int     proc_nbr;//numero du processus
	int     carry;
	int     lives;//lives du processus
	int     instruction;//0 si aucune instruction
	int     description;
	int     registers[16];///////////

}               t_processes;

typedef struct  s_counters
{
	int     cycle_to_die;
	int     lives;//total de lives
	int     non_decrementation;
	int     nbr_proc;//nombre de processus
	char    *vm;
}               t_counters;

typedef struct	s_param
{
	int		nb_player;
	char	line[2875];
	int		i;
	int		fd;
}				t_param;

int				ft_check_magic(int fd, t_header *header);
void			ft_check_nbr_inst(int fd, t_header *header);
void			ft_check_name(int fd, t_header *header);
void			ft_check_comment(int fd, t_header *header);
void			ft_check_inst(int fd, t_header *header);

#endif
