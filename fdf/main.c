/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:01:32 by ekinnune          #+#    #+#             */
/*   Updated: 2021/01/04 10:40:08 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*ft_fdf_init(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->window = 0;
	fdf->colour = mlx_get_color_value(fdf->mlx_ptr, 16777215);
	fdf->name = 0;
	fdf->x_max = 0;
	fdf->y_max = 0;
	fdf->map = 0;
	fdf->xs = 0;
	fdf->ys = 0;
	fdf->col_len = 0;
	fdf->space = 10;
	fdf->tilt = 1;
	fdf->padding = 100;
	fdf->x0 = 0;
	fdf->y0 = 0;
	fdf->x1 = 0;
	fdf->y1 = 0;
	fdf->y = 0;
	fdf->x = 0;
	fdf->delta_x = 0;
	fdf->delta_y = 0;
	fdf->t = 0;
	return (fdf);
}

int		main(int argc, char **argv)
{
	t_fdf *fdf;

	if (argc != 2)
	{
		ft_usage();
	}
	if (!(fdf = malloc(sizeof(t_fdf))))
	{
		return (1);
	}
	ft_fdf_init(fdf);
	ft_convert_file(fdf, argv[1]);
//1024
	ft_new_window(fdf, 768, 768, argv[1]);
	ft_yx_malloc(fdf);
	ft_yx_assign(fdf, "top", 0, 0);
	ft_orthographic(fdf, "top");
	ft_make_border(fdf);
	mlx_key_hook(fdf->window, ft_key_input, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
