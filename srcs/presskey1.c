/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presskey1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:37:40 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/06 15:56:13 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	cameramove(int key, t_fdf *fdf)
{
	if (key == 13 || key == 119)
		fdf->cam.cord.y -= fdf->cam.speed;
	if (key == 1 || key == 115)
		fdf->cam.cord.y += fdf->cam.speed;
	if (key == 0 || key == 97)
		fdf->cam.cord.x -= fdf->cam.speed;
	if (key == 2 || key == 100)
		fdf->cam.cord.x += fdf->cam.speed;
}

void	zoommap(t_fdf *fdf, int key)
{
	if (key == 61 || key == 24 || key == 45 || key == 27)
	{
		if (key == 61 || key == 24)
			fdf->cellsize += 1;
		if (key == 45 || key == 27)
			if (fdf->cellsize > 1)
				fdf->cellsize -= 1;
	}
}

void	camerarotate(int key, t_fdf *fdf)
{
	if (key == 123 || key == 65362)
		fdf->cam.angle.x += 0.1f;
	if (key == 124 || key == 65364)
		fdf->cam.angle.x -= 0.1f;
	if (key == 126 || key == 65363)
		fdf->cam.angle.y += 0.1f;
	if (key == 125 || key == 65361)
		fdf->cam.angle.y -= 0.1f;
	if (key == 12 || key == 113)
		fdf->cam.angle.z += 0.1f;
	if (key == 14 || key == 101)
		fdf->cam.angle.z -= 0.1f;
	fdfrotate(fdf);
	fdf->cam.angle = setdpoint(0, 0, 0);
}

void	checkresizewindow(t_fdf *fdf, int key)
{
	if (key == 15 || key == 114)
	{
		editwindow(&fdf->window, fdf->window->size_x + 10,
		fdf->window->size_y + 10, fdf->window->title);
		resizeimage(fdf->window->mlx_ptr, &fdf->image,
		plusepoint(fdf->image->size, 10, 10, 0));
		update_input(fdf);
	}
}

int		keyboarddown(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (isrotate(fdf->map, key))
		camerarotate(key, fdf);
	if (ismove(key))
		cameramove(key, fdf);
	zoommap(fdf, key);
	if (key == 53 || key == 65307)
		winclose(0);
	if (key == 3)
		foto(fdf);
	if (key == 17)
		switchcamtype(fdf);
	if (key == 8 || key == 99)
	{
		fdf->map.cmode = fdf->map.cmode == 0 ? 1 : 0;
		switchcolor(fdf, fdf->map.cmode);
	}
	checkresizewindow(fdf, key);
	draw(fdf);
	return (0);
}
