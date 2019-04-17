/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlinelerp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:36:40 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:37:37 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		drawlinelerplow(t_fdf *fdf, t_mappoint start, t_mappoint end)
{
	t_point		delta;
	t_point		edi;
	t_dpoint	cord;

	delta = setpoint(fabs(start.cord.x - end.cord.x),
	fabs(start.cord.y - end.cord.y), fabs(start.cord.y - end.cord.y));
	edi.x = 0;
	edi.y = end.cord.y - start.cord.y;
	edi.y > 0 ? edi.y = 1 : 0;
	edi.y < 0 ? edi.y = -1 : 0;
	cord = start.cord;
	edi.z = 0;
	while (edi.z < end.cord.x - start.cord.x)
	{
		put_pixel_to_image(fdf->image, setpoint(cord.x + edi.z, cord.y, 0),
		ft_lerpcolor(start.vcolor, end.vcolor, (float)1 / delta.x * edi.z));
		edi.x = edi.x + delta.z;
		if (2 * edi.x >= delta.x)
		{
			cord.y = cord.y + edi.y;
			edi.x = edi.x - delta.x;
		}
		edi.z++;
	}
}

void		drawlinelerphight(t_fdf *fdf, t_mappoint start, t_mappoint end)
{
	t_point		delta;
	t_point		edi;
	t_dpoint	cord;

	delta = setpoint(fabs(start.cord.x - end.cord.x),
	fabs(start.cord.y - end.cord.y), fabs(start.cord.x - end.cord.x));
	edi.x = 0;
	edi.y = end.cord.x - start.cord.x;
	edi.y > 0 ? edi.y = 1 : 0;
	edi.y < 0 ? edi.y = -1 : 0;
	cord = start.cord;
	edi.z = 0;
	while (edi.z < end.cord.y - start.cord.y)
	{
		put_pixel_to_image(fdf->image, setpoint(cord.x, cord.y + edi.z, 0),
		ft_lerpcolor(start.vcolor, end.vcolor, (float)1 / delta.y * edi.z));
		edi.x = edi.x + delta.z;
		if (2 * edi.x >= delta.y)
		{
			cord.x = cord.x + edi.y;
			edi.x = edi.x - delta.y;
		}
		edi.z++;
	}
}

void		drawlinelerp(t_fdf *fdf, t_mappoint start, t_mappoint end)
{
	if (fabs(end.cord.y - start.cord.y) < fabs(end.cord.x - start.cord.x))
	{
		if (start.cord.x > end.cord.x)
			drawlinelerplow(fdf, end, start);
		else
			drawlinelerplow(fdf, start, end);
	}
	else
	{
		if (start.cord.y > end.cord.y)
			drawlinelerphight(fdf, end, start);
		else
			drawlinelerphight(fdf, start, end);
	}
}
