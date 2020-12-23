/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:01:18 by ekinnune          #+#    #+#             */
/*   Updated: 2020/12/23 14:36:17 by ekinnune         ###   ########.fr       */
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

int		ft_change_view(t_fdf *fdf, int view)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->window);
	if (view == 0)
	{
		ft_tilted_view(fdf);
		return (1);
	}
	else if (view == 1)
	{
		ft_orthographic(fdf, "side");
	}
	else
	{
		ft_orthographic(fdf, "top");
	}
	return (0);
}

int		ft_key_input(int key_code, t_fdf *fdf)
{
	static int view = 1;

	if (key_code == 49)
		view = ft_change_view(fdf, view);
	if (key_code == 125)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->window);
		if (fdf->space > 1)
			fdf->space--;
		ft_tilted_view(fdf);
	}
	if (key_code == 126)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->window);
		fdf->space++;
		ft_tilted_view(fdf);
	}
	if (key_code == 124)
		ft_change_view(fdf, 1);
	if (key_code == 123)
		ft_change_view(fdf, 2);
	if (key_code == 53)
		exit(0);
	return (0);
}
