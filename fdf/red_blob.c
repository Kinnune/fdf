/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_blob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:01:45 by ekinnune          #+#    #+#             */
/*   Updated: 2021/01/03 14:29:03 by ekinnune         ###   ########.fr       */
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

float	ft_diagonal_distance(t_fdf *fdf)
{
	float dis_x;
	float dis_y;

	dis_x = abs(fdf->x0 - fdf->x1);
	dis_y = abs(fdf->y - fdf->y1);
	return (ft_max(dis_y, dis_x));
}

void	ft_round_point(t_fdf *fdf)
{
	fdf->delta_x = round(fdf->delta_x);
	fdf->delta_y = round(fdf->delta_y);
}

float	ft_lerp(float start, float end, float t)
{
	return (start + t * (end - start));
}

void	ft_draw_line(t_fdf *fdf)
{
	float step;
	float n;

	step = 0;
	fdf->t = 0;
	n = ft_diagonal_distance(fdf);
	while (step <= n)
	{
		fdf->t = n;
		if (fdf->t != 0)
		{
			fdf->t = step / n;
		}
		fdf->delta_x = ft_lerp(fdf->x0, fdf->x1, fdf->t);
		fdf->delta_y = ft_lerp(fdf->y0, fdf->y1, fdf->t);
		ft_round_point(fdf);
		if (fdf->delta_x >= 0 && fdf->delta_x < fdf->x_win
			&& fdf->delta_y >= 0 && fdf->delta_y < fdf->y_win)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->window, fdf->delta_x,
							fdf->delta_y, fdf->colour);
		}
		step++;
	}
}
