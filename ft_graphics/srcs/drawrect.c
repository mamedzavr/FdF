/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawrect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:13:22 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:39:45 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

void		drawrect(t_image *img, t_rect *rect, t_rgbcolor color)
{
	t_point cord;

	cord.y = rect->start->y;
	while (cord.y <= rect->start->y + rect->height)
	{
		cord.x = rect->start->x;
		while (cord.x <= rect->start->x + rect->width)
		{
			if (cord.x < rect->start->x + rect->width &&
			(cord.y == rect->start->y || cord.y == rect->start->y
			+ rect->height))
				put_pixel_to_image(img, cord, color);
			if (cord.y < rect->start->y + rect->height &&
			(cord.x == rect->start->x || cord.x == rect->start->x
			+ rect->width))
				put_pixel_to_image(img, cord, color);
			cord.x++;
		}
		cord.y++;
	}
}
