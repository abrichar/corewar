/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:46:23 by abrichar          #+#    #+#             */
/*   Updated: 2018/05/04 00:26:12 by ardurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void				write_dir(char *dir, t_asm *env, t_op actual,
						unsigned int size_to_here)
{
	int	to_write;

	if ((search_char(dir, LABEL_CHAR)) == -1)
	{
		to_write = ft_atoi(ft_strsub(dir, 1,
									ft_strlen(dir)));
		if (actual.opcode >= 9 && actual.opcode != 13 && actual.opcode <= 15)
			ft_putshort_fd(to_write, env->fd);
		else
			ft_putint_fd(to_write, env->fd);
	}
	else
		write_label(dir, actual, env, size_to_here);
}

static void				write_ind(char *ind, t_asm *env,
								unsigned int size_to_here)
{
	int			to_write;
	char		*to_search;
	t_parsing	*tmp;

	to_write = 0;
	to_search = NULL;
	tmp = NULL;
	if (ind[0] != ':')
		to_write = ft_atoi(ft_strsub(ind, 0,
									ft_strlen(ind)));
	else
	{
		tmp = env->buff;
		to_search = ft_strsub(ind, 1, ft_strlen(ind) - 1);
		to_write = write_label2(tmp, to_search, size_to_here, env);
	}
	ft_putshort_fd(to_write, env->fd);
	free(to_search);
	free(tmp);
}

void					write_params(t_asm *env, char *split, t_op actual,
					unsigned int size_to_here)
{
	char			**splited;
	int				i;
	int				to_write;

	splited = ft_strsplit(split, SEPARATOR_CHAR);
	clear_split(splited);
	i = -1;
	to_write = 0;
	while (++i < tab_len(splited))
	{
		if (check_param(splited[i]) == REG_CODE)
		{
			to_write = ft_atoi(ft_strsub(splited[i], 1,
										ft_strlen(splited[i])));
			write(env->fd, &to_write, 1);
		}
		else if (check_param(splited[i]) == IND_CODE)
		{
			write_ind(splited[i], env, size_to_here);
		}
		else
			write_dir(splited[i], env, actual, size_to_here);
	}
	free(splited);
}
