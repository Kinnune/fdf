/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:01:18 by ekinnune          #+#    #+#             */
/*   Updated: 2021/01/06 14:56:08 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_max(float num1, float num2)
{
	if (num1 > num2)
	{
		return (num1);
	}
	else
	{
		return (num2);
	}
}

void	ft_round_point(t_fdf *fdf)
{
	fdf->delta_x = round(fdf->delta_x);
	fdf->delta_y = round(fdf->delta_y);
}

float	ft_abs(float num)
{
	if (num < 0)
	{
		return (num * -1);
	}
	return (num);
}

float	ft_diagonal_distance(t_fdf *fdf)
{
	float dis_x;
	float dis_y;

	dis_x = ft_abs(fdf->x0 - fdf->x1);
	dis_y = ft_abs(fdf->y - fdf->y1);
	return (ft_max(dis_y, dis_x));
}

float	ft_lerp(float start, float end, float t)
{
	return (start + t * (end - start));
}