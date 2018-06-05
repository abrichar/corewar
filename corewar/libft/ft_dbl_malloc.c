/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:16:21 by kgricour          #+#    #+#             */
/*   Updated: 2018/04/19 22:04:37 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_dbl_malloc(int nb_x, int nb_y)
{
	int		i;
	char	**tab;

	i = 0;
	tab = NULL;
	if (!(tab = (char **)malloc(sizeof(char *) * nb_y + 1)))
		return (NULL);
	tab[nb_y] = 0;
	while (tab[i])
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * nb_x + 1)))
			return (NULL);
		tab[i][nb_x] = '\0';
		i++;
	}
	return (tab);
}
