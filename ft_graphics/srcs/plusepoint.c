/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plusepoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:45:12 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:42:11 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

void		plusepointptr(t_point *point, int x, int y, int z)
{
	if (point != NULL)
	{
		point->x += x;
		point->y += y;
		point->z += z;
	}
}

t_point		plusepoint(t_point p, int x, int y, int z)
{
	p.x += x;
	p.y += y;
	p.z += z;
	return (p);
}

void		plusefpoint(t_fpoint *point, float x, float y, float z)
{
	if (point != NULL)
	{
		point->x += x;
		point->y += y;
		point->z += z;
	}
}

t_dpoint	plusedpoint(t_dpoint point, double x, double y, double z)
{
	point.x += x;
	point.y += y;
	point.z += z;
	return (point);
}
