/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:46:23 by abrichar          #+#    #+#             */
/*   Updated: 2018/07/03 18:09:11 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void				write_dir(char *dir, t_asm *env, t_op actual,
						unsigned int size_to_here)
{
	int		to_write;
	char	*str_sub;

	if ((search_char(dir, LABEL_CHAR)) == -1)
	{
		str_sub = ft_strsub(dir, 1, ft_strlen(dir));
		to_write = ft_atoi(str_sub);
		free(str_sub);
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
	char		*str_sub;
	t_parsing	*tmp;

	to_write = 0;
	to_search = NULL;
	tmp = NULL;
	if (ind[0] != ':')
	{
		str_sub = ft_strsub(ind, 0, ft_strlen(ind));
		to_write = ft_atoi(str_sub);
		free(str_sub);
	}
	else
	{
		tmp = env->buff;
		to_search = ft_strsub(ind, 1, ft_strlen(ind) - 1);
		to_write = write_label2(tmp, to_search, size_to_here, env);
	}
	ft_putshort_fd(to_write, env->fd);
	if (to_search)
		free(to_search);
//	if (tmp)<-----------------------------kev
//		free(tmp);<-----------------------kev
}

void					write_params(t_asm *env, char *split, t_op actual,
					unsigned int size_to_here)
{
	char			**splited;
	char			**ptr_trash;//<---------------kev
	int				i;
	int				to_write;
	char			*str_sub;

	splited = ft_strsplit(split, SEPARATOR_CHAR);
	ptr_trash = splited;//<---------------kev
	clear_split(splited);
	i = -1;
	to_write = 0;
	while (++i < tab_len(splited))
	{
		if (check_param(splited[i]) == REG_CODE)
		{
			str_sub = ft_strsub(splited[i], 1,	ft_strlen(splited[i]));
			to_write = ft_atoi(str_sub);
		free(str_sub);
			write(env->fd, &to_write, 1);
		}
		else if (check_param(splited[i]) == IND_CODE)
		{
			write_ind(splited[i], env, size_to_here);
		}
		else
			write_dir(splited[i], env, actual, size_to_here);
	}
	i = 0;//<---------------kev
	while (ptr_trash[i])//<---------------kev
	{
		free(ptr_trash[i]);//<---------------kev
		i++;//<---------------kev
	}
	if (splited)
		free(splited);
}
