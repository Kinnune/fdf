/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:01:18 by ekinnune          #+#    #+#             */
/*   Updated: 2021/01/04 10:54:45 by ekinnune         ###   ########.fr       */
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
	mlx_clear_window(fdf->mlx_ptr, fdf->window);
	ft_make_border(fdf);
	if (view == 1)
		ft_orthographic(fdf, "side");
	else if (view == 126)
	{
		fdf->space *= 2;
		fdf->tilt *= 2;
		ft_tilted_view(fdf);
	}
	else if (view == 125)
	{
		if (fdf->space > 5)
		{
			fdf->space /= 2;
			fdf->tilt /= 2;
		}
		ft_tilted_view(fdf);
	}
	else
		ft_orthographic(fdf, "top");
}

int		ft_key_input(int key_code, t_fdf *fdf)
{
	if (key_code == 125)
	{
		ft_change_view(fdf, key_code);
	}
	if (key_code == 126)
	{
		ft_change_view(fdf, key_code);
	}
	if (key_code == 124)
	{
		ft_change_view(fdf, 1);
	}
	if (key_code == 123)
	{
		ft_change_view(fdf, 2);
	}
	if (key_code == 53)
	{
		exit(0);
	}
	return (0);
}
