/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:40:58 by eliajin           #+#    #+#             */
/*   Updated: 2018/05/04 00:21:01 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_epur_str(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((dest = (char*)malloc(sizeof(char*) * ft_strlen(str))) == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
				i++;
			if (j != 0 && str[i] != '\0')
				dest[j++] = ' ';
		}
		dest[j++] = str[i++];
	}
	dest[j] = '\0';
	return (dest);
}
