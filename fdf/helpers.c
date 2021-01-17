/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:01:18 by ekinnune          #+#    #+#             */
/*   Updated: 2021/01/08 15:47:43 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_usage(void)
{
	ft_putstr("Usage : ./fdf <filename>\n");
	exit(0);
}

int		ft_new_window(t_fdf *fdf, int x, int y, char *name)
{
	fdf->x_win = x;
	fdf->y_win = y;
	fdf->name = name;
	if (fdf->window)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->window);
		mlx_destroy_window(fdf->mlx_ptr, fdf->window);
	}
	fdf->window = mlx_new_window(fdf->mlx_ptr, x, y, name);
	return (1);
}

void	ft_change_view(t_fdf *fdf, int view)
{
	ft_draw(fdf, 1);
	if (view == 65362)
	{
		fdf->space *= 2;
		fdf->tilt *= 2;
		ft_tilted_view(fdf);
	}
	else if (view == 65364)
	{
		if (fdf->space > 5)
		{
			fdf->space /= 2;
			fdf->tilt /= 2;
		}
		ft_tilted_view(fdf);
	}
	else if (view == 65361)
		ft_orthographic(fdf, "side");
	else
		ft_orthographic(fdf, "top");
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->window, fdf->image, 0, 15);
}

int		ft_key_input(int key_code, t_fdf *fdf)
{
	if (key_code == 65362)
	{
		ft_change_view(fdf, key_code);
	}
	if (key_code == 65364)
	{
		ft_change_view(fdf, key_code);
	}
	if (key_code == 65361)
	{
		ft_change_view(fdf, key_code);
	}
	if (key_code == 65363)
	{
		ft_change_view(fdf, key_code);
	}
	if (key_code == 65307)
	{
		exit(0);
	}
	return (0);
}
