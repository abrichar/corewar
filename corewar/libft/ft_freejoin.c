/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 20:34:51 by kgricour          #+#    #+#             */
/*   Updated: 2018/03/06 23:26:11 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freejoin(char *s1, char *s2, int n)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = ft_strjoin(s1, s2);
	if (n == 0)
		ft_strdel(&s1);
	if (n == 1)
		ft_strdel(&s2);
	if (n == 2)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (new);
}
