/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:03:43 by kgricour          #+#    #+#             */
/*   Updated: 2017/11/20 09:57:45 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;

	if (size > 4294967295)
		return (NULL);
	if ((mem = (char *)malloc(sizeof(*mem) * (size + 1))) == NULL)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
