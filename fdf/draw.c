/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:00:46 by ekinnune          #+#    #+#             */
/*   Updated: 2021/01/08 14:30:58 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_horizontal(t_fdf *fdf, int erease)
{
	int y;
	int x;

	y = 0;
	while (fdf->map[y])
	{
		x = 0;
		while (x < (fdf->col_len[y] - 1))
		{
			fdf->x0 = fdf->xs[y][x];
			fdf->x1 = fdf->xs[y][x + 1];
			fdf->y0 = fdf->padding + fdf->ys[y][x];
			fdf->y1 = fdf->padding + fdf->ys[y][x + 1];
			ft_draw_line(fdf, erease);
			x++;
		}
		y++;
	}
}

void	ft_draw_vertical(t_fdf *fdf, int erease)
{
	int y;
	int x;

	y = 0;
	while (fdf->map[y + 1])
	{
		x = 0;
		while (x < fdf->col_len[y] && x < fdf->col_len[y + 1])
		{
			fdf->x0 = fdf->xs[y][x];
			fdf->x1 = fdf->xs[y + 1][x];
			fdf->y0 = fdf->padding + fdf->ys[y][x];
			fdf->y1 = fdf->padding + fdf->ys[y + 1][x];
			ft_draw_line(fdf, erease);
			x++;
		}
		y++;
	}
}

void	ft_draw(t_fdf *fdf, int erease)
{
	ft_draw_horizontal(fdf, erease);
	ft_draw_vertical(fdf, erease);
}
