/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:18:32 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/06 16:04:27 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mappoint	translate(t_mappoint point, t_fdf *fdf)
{
	point.cord = multdpoint(point.cord, fdf->cellsize, fdf->cellsize, 0);
	fdf->map.drawcenter = setdpoint(((fdf->map.size.x - 1) * fdf->cellsize)
	/ 2, ((fdf->map.size.y - 1) * fdf->cellsize) / 2, 0);
	if (fdf->map.type == PARALLE)
		fdf->map.drawcenter = setdpoint(((fdf->map.size.x - 1) * fdf->cellsize)
		/ 3, ((fdf->map.size.y - 1) * fdf->cellsize) / 3, 0);
	point.cord = minusdpoint(point.cord, fdf->map.drawcenter.x,
	fdf->map.drawcenter.y, 0);
	point.cord = plusedpoint(point.cord, fdf->cam.cord.x, fdf->cam.cord.y, 0);
	return (point);
}

static	void		crutchmap(t_fdf *fdf, t_point cord)
{
	t_mappoint	start;
	t_mappoint	end;

	start = translate(fdf->map.view[cord.y][cord.x], fdf);
	put_pixel_to_image(fdf->image, setpoint(start.cord.x,
	start.cord.y, start.cord.z), *start.vcolor);
	if (cord.x + 1 < fdf->map.size.x)
	{
		end = translate(fdf->map.view[cord.y][cord.x + 1], fdf);
		drawlinelerp(fdf, start, end);
	}
	if (cord.y + 1 < fdf->map.size.y)
	{
		end = translate(fdf->map.view[cord.y + 1][cord.x], fdf);
		drawlinelerp(fdf, start, end);
	}
}

void				drawmap(t_fdf *fdf)
{
	t_point		cord;

	cord.y = 0;
	while (cord.y < fdf->map.size.y)
	{
		cord.x = 0;
		while (cord.x < fdf->map.size.x)
		{
			crutchmap(fdf, cord);
			cord.x++;
		}
		cord.y++;
	}
}
