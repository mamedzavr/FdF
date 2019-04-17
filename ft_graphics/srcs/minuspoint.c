/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minuspoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:42:42 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:42:59 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

void		minuspoint(t_point *point, int x, int y, int z)
{
	if (point != NULL)
	{
		point->x -= x;
		point->y -= y;
		point->z -= z;
	}
}

void		minusfpoint(t_fpoint *point, float x, float y, float z)
{
	if (point != NULL)
	{
		point->x -= x;
		point->y -= y;
		point->z -= z;
	}
}

t_dpoint	minusdpoint(t_dpoint point, double x, double y, double z)
{
	point.x -= x;
	point.y -= y;
	point.z -= z;
	return (point);
}
