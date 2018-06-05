/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:32:51 by kgricour          #+#    #+#             */
/*   Updated: 2018/04/24 22:07:31 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_sqrt(float number)
{
	long		i;
	float		x;
	float		y;
	const float	f = 1.5F;

	x = number * 0.5F;
	y = number;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (f - (x * y * y));
	return (number * y);
}
