/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xs_and_ys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:02:03 by ekinnune          #+#    #+#             */
/*   Updated: 2020/12/23 14:30:20 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_yx_malloc(t_fdf *fdf)
{
	int y;

	y = 0;
	fdf->xs = (int **)malloc(sizeof(int *) * (fdf->y_max + 1));
	fdf->ys = (int **)malloc(sizeof(int *) * (fdf->y_max + 1));
	if (!fdf->xs || !fdf->ys)
	{
		exit(1);
	}
	fdf->xs[fdf->y_max] = 0;
	fdf->ys[fdf->y_max] = 0;
	while(fdf->map[y])
	{
		fdf->xs[y] = (int *)malloc(sizeof(int) * fdf->col_len[y]);
		fdf->ys[y] = (int *)malloc(sizeof(int) * fdf->col_len[y]);
		if (!fdf->xs[y] || !fdf->ys[y])
		{
			exit(1);
		}
		y++;
	}
	return (1);
}

void	ft_yx_assign(t_fdf *fdf, char *view)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (fdf->map[y])
	{
		while (x < fdf->col_len[y])
		{
			fdf->xs[y][x] = (x * fdf->space) + 1;
			if (ft_strequ(view , "top"))
			{
				fdf->ys[y][x] = (y * fdf->space) + 1;
			}
			else
			{
				fdf->ys[y][x] = ((fdf->y_win / 2) - fdf->padding)
				+ (fdf->map[y][x] * fdf->space);
			}
			if (fdf->ys[y][x] >= (fdf->y_win - fdf->padding)
			|| fdf->xs[y][x] >= fdf->x_win)
			{
				if (fdf->space > 1)
				{
					fdf->space--;
					ft_yx_assign(fdf, view);
					return ;
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_yx_tilted(t_fdf *fdf)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (fdf->map[y])
	{
		while (x < fdf->col_len[y])
		{
			fdf->xs[y][x] = (x * fdf->space) + ((fdf->y_max * fdf->space)
			- (y * fdf->space));
			fdf->ys[y][x] = ((y * fdf->space) - (fdf->map[y][x] * fdf->tilt))
			+ (x * fdf->space);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_orthographic(t_fdf *fdf, char *view)
{
	ft_yx_assign(fdf, view);
	ft_draw(fdf);
}

void	ft_tilted_view(t_fdf *fdf)
{
	ft_yx_tilted(fdf);
	ft_draw(fdf);
}