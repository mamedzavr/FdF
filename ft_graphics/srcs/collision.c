/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:30:13 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:34:54 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

int			pointtorectcollision(t_point point, t_rect rect)
{
	if (rect.start->x < point.x && rect.start->y < point.y)
		if (rect.start->x + rect.width > point.x &&
		rect.start->y + rect.height > point.y)
		{
			return (1);
		}
	return (0);
}

int			recttorectcollision(t_rect *rect1, t_rect *rect2)
{
	if (rect1->start->x < rect2->start->x &&
	rect1->start->y < rect2->start->y)
		if (rect1->start->x + rect1->width > rect2->start->x + rect2->width &&
		rect1->start->y + rect1->height > rect2->start->y + rect2->height)
			return (1);
	return (0);
}
