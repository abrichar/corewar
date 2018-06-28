/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 19:16:18 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/28 19:20:52 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "op.h"
# include "ft_printf.h"
# include <ncurses.h>

# define TITLE "CoReWaR VM by Mpascaud-Kgricour-Abrichar-Cholm"
# define USAGE "./corewar [[-V][-dump n][-n number[1|2|3|4]] your_champ.cor]"

typedef struct	s_processes
{
	int					pc;
	int					wait;
	int					size;
	int					carry;
	int					lives;
	int					player;
	int					proc_nbr;
	int					size_param[4];
	int					description[3];
	int					registers[REG_NUMBER];
	char				instruction[5];
	struct s_processes	*start;
	struct s_processes	*next;

}				t_processes;

typedef struct	s_counters
{
	int				lives;
	int				cycles;
	int				nbr_proc;
	int				last_live;
	int				proc_alive;
	int				cycle_to_die;
	int				total_cycles;
	int				non_decrementation;
	int				period_lives[4];
	unsigned char	*vm;
	unsigned char	*color;
}				t_counters;

typedef struct	s_param
{
	int			ncurse;
	int			dump;
	int			nb_player;
	char		line[2875];
	int			argc;
	char		**argv;
	int			i;
	int			fd;
}				t_param;

/*
** ft_get_op.c
*/

int				ft_nb_player(t_param *param, t_header **header);

/*
** ft_adress_champ.c
*/

void			ft_addr_start(t_param *param, t_header *header);
void			ft_addr_start(t_param *param, t_header *header);

/*
** ft_valid_player.c
*/

int				ft_check_number_player(t_header *header, t_param *param);

/*
** ft_check_and_start.c
*/

int				ft_start(t_processes *p, t_header *h, t_param *pm,
				t_counters *c);
void			ft_init_period_lives(t_counters *c);

/*
** ft_init_vm.c
*/

void			ft_load_champ_in_vm(t_header *h, t_counters *c);
int				ft_init_counters(t_counters *c, t_header *h, t_param *pm);
int				ft_new_process(t_processes *p, t_header *h);
int				ft_add_process(t_processes *p, t_header *h, int proc_nbr);
int				ft_init_processes(t_processes *p, t_header *h);

/*
** ft_vm.c
*/

void			ft_check_lives2(t_processes *p_start, t_counters *c);
void			ft_check_lives(t_processes *p_start, t_counters *c);
void			ft_vm(t_processes *p, t_counters *c, t_param *pm, t_header *h);
void			ft_cycle_to_die(t_counters *c);
int				ft_init_vm(t_processes **p, t_counters **c, t_header *h,
				t_param *pm);
/*
** ft_free_vm.c
*/

void			ft_medium_free(t_processes *p, t_counters *c, t_header
				*header_first);
void			ft_final_free(t_processes *p, t_counters *c);
void			ft_free(t_header *header);

/*
** ft_ncurse.c
*/

void			ft_ncurse(t_counters *c, t_processes *p, t_param *param,
				t_header *h);
void			ft_printw_memory(t_counters *c);

/*
** ft_check_champ.c
*/

int				ft_check_magic(int fd, t_header *header);
int				ft_check_inst(int fd, t_header *header);
void			ft_check_nbr_inst(int fd, t_header *header);
void			ft_check_name(int fd, t_header *header);
void			ft_check_comment(int fd, t_header *header);

/*
** ft_process.c
*/

void			ft_process(t_processes *p, t_counters *c, t_param *param,
				t_header *header);

/*
** ft_parse_instruct.c
*/

void			ft_get_ocp(t_processes *p, t_counters *c, int op, int bin);
void			ft_check_ocp(t_processes *p, t_counters *c, int op);
int				ft_instruct_parse(t_processes *p, t_counters *c, int op);

/*
** ft_malloc_vm.c
*/

t_header		*ft_init(t_param *param, t_header **header, int ac, char **av);
t_header		*ft_create_new_header(t_header *header);
void			ft_init_color(t_counters *c);
int				ft_check_player(int fd, t_header *header);
int				ft_malloc_p_c(t_processes **p, t_counters **c);

/*
** ft_dump.c
*/

void			ft_dump(t_counters *c, t_processes *p);
int				ft_check_dump(t_param *pm, int *check_arg);

/*
** ft_tool_instruction.c
*/

int				ft_exist(int nbr_player, t_header *header);
int				ft_take_parameter(t_processes *p, t_counters *c, int *i,
				int param);
int				ft_read_ind(t_processes *p, t_counters *c, unsigned int first);
int				ft_read_two(t_processes *p, t_counters *c, unsigned int first);
void			ft_write_ind(t_processes *p, t_counters *c, int first,
				int second);

/*
** ft_instruction.c
*/

void			ft_live(t_processes *p, t_counters *c, t_header *h,
				t_param *pm);
void			ft_ld(t_processes *p, t_counters *c);
void			ft_st(t_processes *p, t_counters *c);
void			ft_zjmp(t_processes *p, t_counters *c);
void			ft_fork(t_processes *p, t_counters *c, t_header *h);

/*
** ft_instruction_two.c
*/

void			ft_ldi(t_processes *p, t_counters *c);
void			ft_sti(t_processes *p, t_counters *c);
int				ft_invalid_ldi(t_processes *p, int first, int two, int three);

/*
** ft_instruction_three.c
*/

void			ft_add(t_processes *p, t_counters *c);
void			ft_sub(t_processes *p, t_counters *c);
void			ft_and(t_processes *p, t_counters *c);
void			ft_or(t_processes *p, t_counters *c);
void			ft_xor(t_processes *p, t_counters *c);

/*
** ft_instruction_four.c
*/

void			ft_lld(t_processes *p, t_counters *c);
void			ft_lldi(t_processes *p, t_counters *c);

/*
** ft_instruction_five.c
*/

void			ft_lfork(t_processes *p, t_counters *c, t_header *h);
void			ft_aff(t_processes *p, t_counters *c, t_header *h, t_param *pm);
int				ft_get_arg(t_processes *p, t_counters *c, int arg, int num_arg);
int				ft_val_reg(int nb);

/*
** ft_is_win.c
*/

int				ft_at_least_one_process(t_processes *p);
void			ft_there_is_win(t_param *pm, t_header *h, t_counters *c);
void			ft_there_isnt_win(t_param *pm);
void			ft_show_winner(t_counters *c, t_header *header, t_param *param);

/*
** ft_view.c
*/

void			ft_show_player_x(t_header *h, t_counters *c, int *space);
void			ft_show_player(t_counters *c, t_header *h, t_param *pm);
void			ft_show_info_vm(t_counters *c);
void			ft_color_pc(t_counters *c, t_processes *p, int mode);
void			ft_init_color_pc(t_counters *c, t_processes *p);

/*
** ft_is_exist.c
*/

int				ft_is_not_exist(int nbr_check_player);
int				ft_check_number_player(t_header *header, t_param *param);
int				ft_is_exist(t_header *header, int nb);
void			ft_is_exist_2(t_header **h, char **argv, int *i, int *nbr);

static const t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, &ft_live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, &ft_ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, &ft_st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, &ft_add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, &ft_sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, &ft_and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, &ft_or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, &ft_xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, &ft_zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, &ft_ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, &ft_sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, &ft_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, &ft_lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, &ft_lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, &ft_lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, &ft_aff},
};

#endif
