/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:24:13 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/06 17:50:08 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "input.h"

int			isheight(t_mappoint **p, t_point cord, int max, int min)
{
	return (p[cord.y][cord.x].cord.z <= max && p[cord.y][cord.x].cord.z >= min);
}

void		colormap(t_fdf *fdf)
{
	t_point cord;

	cord.y = 0;
	while (cord.y < fdf->map.size.y)
	{
		cord.x = 0;
		while (cord.x < fdf->map.size.x)
		{
			if (isheight(fdf->map.map, cord, fdf->map.max, fdf->map.max * 0.8f))
				fdf->map.map[cord.y][cord.x].customcolor = fdf->map.color[0];
			else if (isheight(fdf->map.map, cord, fdf->map.max * 0.8f,
			fdf->map.max * 0.5f))
				fdf->map.map[cord.y][cord.x].customcolor = fdf->map.color[1];
			else if (isheight(fdf->map.map, cord, fdf->map.max * 0.5f,
			fdf->map.max * 0.3f))
				fdf->map.map[cord.y][cord.x].customcolor = fdf->map.color[2];
			else if (isheight(fdf->map.map, cord, fdf->map.max * 0.3f,
			fdf->map.max * 0.2f))
				fdf->map.map[cord.y][cord.x].customcolor = fdf->map.color[3];
			else
				fdf->map.map[cord.y][cord.x].customcolor = fdf->map.color[4];
			cord.x++;
		}
		cord.y++;
	}
}

void		defaultccolor(t_fdf *fdf)
{
	fdf->map.color[0] = setcolor(255, 255, 255);
	fdf->map.color[1] = setcolor(130, 130, 130);
	fdf->map.color[2] = setcolor(46, 114, 24);
	fdf->map.color[3] = setcolor(102, 65, 14);
	fdf->map.color[4] = setcolor(37, 124, 186);
}

t_fdf		*initfdf(int fd, int argc, char **argv)
{
	void		*mlx_ptr;
	t_fdf		*result;

	if (!(result = (t_fdf*)malloc(sizeof(t_fdf))))
		error("Memory is not allocated");
	mlx_ptr = mlx_init();
	result->window = createwindow(mlx_ptr, 800, 600, "Test");
	result->image = createimage(mlx_ptr, setpoint(800, 600, 0));
	result->cam.cord = setpoint(result->window->size_x / 2,
	result->window->size_y / 2, 0);
	result->cam.angle = setdpoint(0, 0, 0);
	result->cam.speed = 5;
	result->cam.camz = 1;
	result->cellsize = 10;
	result->map = readfile(fd);
	result->map.center = setdpoint(result->map.size.x / 2,
	result->map.size.y / 2, 0);
	result->map.view = createview(result->map);
	result->map.type = FREE;
	result->map.cmode = 0;
	argc == 7 ? readcollors(result, argv) : defaultccolor(result);
	switchcamtype(result);
	colormap(result);
	switchcolor(result, result->map.cmode);
	return (result);
}

int			main(int argc, char **argv)
{
	t_fdf		*fdf;
	int			fd;

	fd = open(argv[1], O_RDONLY);
	if ((argc != 2 && argc != 7) || fd == -1)
		usage(argv[0]);
	fdf = initfdf(fd, argc, argv);
	update_input(fdf);
	draw(fdf);
	mlx_loop(fdf->window->mlx_ptr);
	return (0);
}
