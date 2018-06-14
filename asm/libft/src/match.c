/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 22:12:08 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/09 17:52:30 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		match(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s2 == '*' && !*s1)
		return (match(s1, s2 + 1));
	else if (*s2 == '*')
		return (match(s1, s2 + 1) || match(s1 + 1, s2));
	else if (*s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	return (0);
}
