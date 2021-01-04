#include "fdf.h"

void	ft_make_border(t_fdf *fdf)
{
	/*
	int bar;

	bar = 0;
	while (bar < 100)
	{
		if (bar >= 90 && bar <= 92)
		{
			fdf->x0 = 1;
			fdf->x1 = fdf->x_win;
			fdf->y0 = bar;
			fdf->y1 = bar;
			ft_draw_line(fdf);
		}
		bar++;
	}*/
	ft_instructions(fdf);
}

void	ft_instructions(t_fdf *fdf)
{
	char *instructions;
	int colour;

	colour = mlx_get_color_value(fdf->mlx_ptr, 16711680);
	instructions = "Press LEFT for ortho top view and RIGHT for ortho side view. UP and DOWN rescale. ESC exits.";
	mlx_string_put(fdf->mlx_ptr, fdf->window, 5, 10, colour, instructions);
}