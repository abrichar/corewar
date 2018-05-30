/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:48:10 by eliajin           #+#    #+#             */
/*   Updated: 2018/05/07 10:38:17 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Ces fonctions servent à vérifier la longueur du nom et du com
** ainsi que de les stocker dans la variable env
*/

static void		check_size2(char *line, char *macro, int index)
{
	if (ft_strcmp(macro, NAME_CMD_STRING) == 0)
	{
		if (ft_strlen(line) <= PROG_NAME_LENGTH)
			return ;
	}
	else if (ft_strcmp(macro, COMMENT_CMD_STRING) == 0)
		if (ft_strlen(line) <= COMMENT_LENGTH)
			return ;
	msg_error("", index);
}

static void		check_size(char *line, t_asm *env, char *macro, int index)
{
	if (ft_strcmp(macro, NAME_CMD_STRING) == 0)
	{
		check_size2(line, macro, index);
		ft_strcpy(env->header->prog_name, line);
		ft_strdel(&line);
		return ;
	}
	if (ft_strcmp(macro, COMMENT_CMD_STRING) == 0)
	{
		check_size2(line, macro, index);
		ft_strcpy(env->header->comment, line);
		ft_strdel(&line);
		return ;
	}
}

/*
** Récupère le name ou le comment
** faire boucle tant que pas trouvé le deuxieme '"', continue a gnl
** et stocker dans une variable
*/

void			dump_header(char *line, t_asm *env, char *macro, int index)
{
	int			i;
	int			j;
	char		*tmp;
	char		*sub;

	i = search_char(line, '"') + 1;
	if (!(tmp = ft_strsub(line, i, ft_strlen(line))))
		msg_error(ERR_MALLOC, 0);
	j = search_char(tmp, '"');
	if (!(sub = ft_strsub(tmp, 0, j)))
		msg_error(ERR_MALLOC, 0);
	ft_strdel(&tmp);
	check_size(sub, env, macro, index);
}
