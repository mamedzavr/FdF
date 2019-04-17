/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:45:15 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:42:49 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

static void	drawlinelow(t_image *img, t_dpoint start,
t_dpoint end, t_rgbcolor color)
{
	t_point	delta;
	int		error;
	t_point	cord;
	int		diry;

	delta = setpoint(fabs(start.x - end.x), fabs(start.y - end.y),
	fabs(start.y - end.y));
	error = 0;
	diry = end.y - start.y;
	diry > 0 ? diry = 1 : 0;
	diry < 0 ? diry = -1 : 0;
	cord = setpoint(start.x, start.y, start.z);
	while (cord.x < end.x)
	{
		put_pixel_to_image(img, cord, color);
		error = error + delta.z;
		if (2 * error >= delta.x)
		{
			cord.y = cord.y + diry;
			error = error - delta.x;
		}
		cord.x++;
	}
}

static void	drawlinehight(t_image *img, t_dpoint start,
t_dpoint end, t_rgbcolor color)
{
	t_point	delta;
	int		error;
	t_point	cord;
	int		dirx;

	delta = setpoint(fabs(start.x - end.x), fabs(start.y - end.y),
	fabs(start.x - end.x));
	error = 0;
	dirx = end.x - start.x;
	dirx > 0 ? dirx = 1 : 0;
	dirx < 0 ? dirx = -1 : 0;
	cord = setpoint(start.x, start.y, start.z);
	while (cord.y < end.y)
	{
		put_pixel_to_image(img, cord, color);
		error = error + delta.z;
		if (2 * error >= delta.x)
		{
			cord.x = cord.x + dirx;
			error = error - delta.y;
		}
		cord.y++;
	}
}

void		drawline(t_image *img, t_dpoint start,
t_dpoint end, t_rgbcolor color)
{
	if (fabs(end.y - start.y) < fabs(end.x - start.x))
	{
		if (start.x > end.x)
			drawlinelow(img, end, start, color);
		else
			drawlinelow(img, start, end, color);
	}
	else
	{
		if (start.y > end.y)
			drawlinehight(img, end, start, color);
		else
			drawlinehight(img, start, end, color);
	}
}
