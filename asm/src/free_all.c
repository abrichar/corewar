/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 00:49:32 by abrichar          #+#    #+#             */
/*   Updated: 2018/06/28 17:40:53 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_all(t_asm *env)
{
	t_parsing *tmp;
	t_parsing *next;

	tmp = env->buff;
	while (tmp != NULL)
	{
		next = tmp->next;
		ft_strdel(&tmp->content);
		free(tmp);
		tmp = next;
	}
	env->buff = NULL;
}

void	free_split(char **split)
{
	int i;

	i = -1;
	while (++i < tab_len(split))
		free(split[i]);
}
