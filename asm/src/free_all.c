/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 00:49:32 by abrichar          #+#    #+#             */
/*   Updated: 2018/05/04 02:40:55 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_all(t_asm *env)
{
	t_parsing	*tmp;

	free(env->champ_name);
	tmp = env->buff;
	while (tmp->next)
	{
		free(&tmp->content);
		tmp = tmp->next;
	}
	free(tmp);
}

void	free_split(char **split)
{
	int i;

	i = -1;
	while (++i < tab_len(split))
		free(split[i]);
}
