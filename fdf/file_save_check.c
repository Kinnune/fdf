/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_save_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:01:07 by ekinnune          #+#    #+#             */
/*   Updated: 2020/12/23 14:10:18 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_convert_file(t_fdf *fdf, char *path)
{
	int fd;
	int y;
	char *line;

	y = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
		exit(1);
	while (get_next_line(fd, &line))
	{
		y++;
		free(line);
	}
	fdf->y_max = y;
	if (!(fdf->col_len = (int *)malloc(sizeof(int) * y)))
		exit (1);
	if (!(fdf->map = (int **)malloc(sizeof(int *) * (y + 1))))
		exit (1);
	fdf->map[y] = 0;
	y = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_split_line(fdf, y++, line);
		free(line);
	}
}

void	ft_split_line(t_fdf *fdf, int y, char *line)
{
	char **line_2d;
	int x;

	x = 0;
	line_2d = ft_strsplit(line, ' ');
	x = ft_check_digit(x, line_2d);
	fdf->col_len[y] = x;
	if (!(fdf->map[y] = (int *)malloc(sizeof(int) * x)))
	{
		exit (1);
	}
	while (x > 0)
	{
		x--;
		fdf->map[y][x] = ft_atoi(line_2d[x]);
	}
	ft_free2d(line_2d);
}

int		ft_check_digit(int x, char **line_2d)
{
	int i;

	i = 0;
	while(line_2d[x])
	{
		if (line_2d[x][0] == '-')
		{
			if (line_2d[x][1] == '\0')
			{
				exit(1);
			}
			i++;
		}
		while (line_2d[x][i])
		{
			if (ft_isdigit(line_2d[x][i]))
			{
				break ;
			}
			else
			{
				exit(1);
			}
			i++;
		}
		i = 0;
		x++;
	}
	return (x);
}
