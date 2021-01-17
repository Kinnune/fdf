/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_blob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:01:45 by ekinnune          #+#    #+#             */
/*   Updated: 2021/01/08 15:48:50 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_fdf *fdf, int erease)
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
			ft_manipulate_image(fdf, erease);
		}
		step++;
	}
}

void	ft_manipulate_image(t_fdf *fdf, int erease)
{
	if (erease)
	{
		fdf->img_data[
			(int)((fdf->delta_y * fdf->x_win) + fdf->delta_x) * 4] = 0;
		fdf->img_data[
			(int)(((fdf->delta_y * fdf->x_win) + fdf->delta_x) * 4) + 1] = 0;
		fdf->img_data[
			(int)(((fdf->delta_y * fdf->x_win) + fdf->delta_x) * 4) + 2] = 0;
	}
	else
	{
		fdf->img_data[
			(int)((fdf->delta_y * fdf->x_win) + fdf->delta_x) * 4
				] = fdf->colour;
		fdf->img_data[
			(int)(((fdf->delta_y * fdf->x_win) + fdf->delta_x) * 4) + 1
				] = fdf->colour;
		fdf->img_data[
			(int)(((fdf->delta_y * fdf->x_win) + fdf->delta_x) * 4) + 2
				] = fdf->colour;
	}
}

float	ft_lerp(float start, float end, float t)
{
	return (start + t * (end - start));
}

void	ft_round_point(t_fdf *fdf)
{
	fdf->delta_x = round(fdf->delta_x);
	fdf->delta_y = round(fdf->delta_y);
}
