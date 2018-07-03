/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:42:16 by eliajin           #+#    #+#             */
/*   Updated: 2018/07/04 00:13:35 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Supprime les commentaires
*/

char	*rm_comment(char *line)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = search_char(line, '#');
	if (i < 0)
		return (line);
	tmp = ft_strsub(line, 0, i);
	ret = ft_epur_str(tmp);
	if (tmp)
		free(tmp);
	return (ret);
}

/*
** fonction servant à supprimer les commentaires dans le header
*/

char	*rm_comment_header(char *line)
{
	char	*tmp;
	int		len;
	char	*ret;
	int		i;

	len = search_char(line, '"') + 1;
	tmp = ft_strsub(line, len, ft_strlen(line));
	i = search_char(tmp, '"');
	if (tmp[i + 1] && tmp[i + 1] != '#' && tmp[i + 1] != ' ')
	{
		free(tmp);//<---------------kev
		return (NULL);
	}
	if (tmp[i + 1] && tmp[i + 1] == ' ')
	{
		if (tmp[i + 2] && tmp[i + 2] != '#')
		{
			free(tmp);//<---------------kev
			return (NULL);
		}
	}
	ret = ft_strsub(line, 0, i + len + 1);
	if (tmp)
		free(tmp);
	return (ret);
}

/*
** fonction traitant le header (name + comment)
*/

int		is_header(char *line, char *macro)
{
	char	*tmp;
	char	*rm_comment;
	char	*ptr_trash;//<---------------kev

	rm_comment = rm_comment_header(line);
	if (rm_comment == NULL)
		return (0);
	tmp = ft_strsub(rm_comment, 0, ft_strlen(macro));
	ptr_trash = tmp;//<---------------kev
	if (ft_strcmp(tmp, macro) != 0)
	{
		free(tmp);//<---------------kev
		free(rm_comment);//<---------------kev
		return (0);
	}
	tmp = ft_strsub(rm_comment, ft_strlen(macro), ft_strlen(rm_comment));
	free(ptr_trash);//<---------------kev
	ptr_trash = tmp;//<---------------kev
	tmp = ft_epur_str(tmp);
	free(ptr_trash);//<---------------kev
	if (rm_comment)
		free(rm_comment);
	if (tmp[0] != '"' || tmp[ft_strlen(tmp) - 1] != '"')
		return (0);
	if (tmp)
		free(tmp);
	return (1);
}
