/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_and_hud.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:01:18 by ekinnune          #+#    #+#             */
/*   Updated: 2021/01/08 16:26:40 by ekinnune         ###   ########.fr       */
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

void	ft_lines(t_fdf *fdf, int colour, int height, int i)
{
	if (i % 5 == 0 && (i <= 75 || i >= 685))
	{
		while (--height)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->window, i, height, colour);
		}
	}
}

void	ft_instructions(t_fdf *fdf)
{
	char	*instructions1;
	char	*instructions2;
	char	cat_instru[200];
	int		colour;
	int		i;

	colour = mlx_get_color_value(fdf->mlx_ptr, 16711680);
	instructions1 = "Press LEFT for side view and RIGHT for top view. ";
	instructions2 = "UP and DOWN rescale in a tilted scene. ESC exits.";
	ft_strcat(cat_instru, instructions1);
	ft_strcat(cat_instru, instructions2);
	mlx_string_put(fdf->mlx_ptr, fdf->window, 88, 12, colour, cat_instru);
	i = 0;
	while (i < fdf->x_win)
	{
		ft_lines(fdf, colour, 14, i);
		mlx_pixel_put(fdf->mlx_ptr, fdf->window, i, 14, colour);
		mlx_pixel_put(fdf->mlx_ptr, fdf->window, i, 0, colour);
		i++;
	}
}
