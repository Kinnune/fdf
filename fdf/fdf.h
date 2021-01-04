/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:02:03 by ekinnune          #+#    #+#             */
/*   Updated: 2021/01/04 10:55:29 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_mms_20191025_beta/mlx.h"
# include <fcntl.h>
# include <math.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

typedef	struct	s_fdf
{
	char		*name;
	void		*mlx_ptr;
	void		*window;
	int			x_max;
	int			y_max;
	int			x_win;
	int			y_win;
	int			colour;
	int			**map;
	int			**xs;
	int			**ys;
	int			*col_len;
	int			space;
	float		tilt;
	int			padding;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			y;
	int			x;
	float		delta_x;
	float		delta_y;
	float		t;
}				t_fdf;

void			ft_make_border(t_fdf *fdf);
void			ft_instructions(t_fdf *fdf);



void			ft_draw(t_fdf *fdf);
void			ft_draw_horizontal(t_fdf *fdf);
void			ft_draw_vertical(t_fdf *fdf);

float			ft_max(float num1, float num2);
float			ft_diagonal_distance(t_fdf *fdf);
void			ft_round_point(t_fdf *fdf);
float			ft_lerp(float start, float end, float t);
void			ft_draw_line(t_fdf *fdf);

t_fdf			*ft_fdf_init(t_fdf *fdf);

void			ft_yx_tilted(t_fdf *fdf);
int				ft_yx_malloc(t_fdf *fdf);
void			ft_yx_assign(t_fdf *fdf, char *view, int x, int y);
void			ft_orthographic(t_fdf *fdf, char *view);
void			ft_tilted_view(t_fdf *fdf);

void			ft_split_line(t_fdf *fdf, int y, char *line);
int				ft_check_digit(int x, char **line_2d);
void			ft_convert_file(t_fdf *fdf, char *path);

void			ft_change_view(t_fdf *fdf, int view);
int				ft_new_window(t_fdf *fdf, int x, int y, char *name);
void			ft_usage(void);
int				ft_key_input(int key_code, t_fdf *fdf);

#endif
