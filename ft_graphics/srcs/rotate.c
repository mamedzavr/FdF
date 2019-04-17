/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:25:30 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:30:53 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

void	xrotate(t_dpoint *point, t_dpoint *center, double angle)
{
	t_dpoint	pre;

	pre = setdpoint(point->x - center->x, point->y - center->y, point->z);
	point->x = pre.x + center->x;
	point->y = pre.y * cos(angle) - pre.z * sin(angle) + center->y;
	point->z = pre.y * sin(angle) + pre.z * cos(angle);
}

void	yrotate(t_dpoint *point, t_dpoint *center, double angle)
{
	t_dpoint	pre;

	pre = setdpoint(point->x - center->x, point->y - center->y, point->z);
	point->x = pre.x * cos(angle) + pre.z * sin(angle) + center->x;
	point->y = pre.y + center->y;
	point->z = -pre.x * sin(angle) + pre.z * cos(angle);
}

void	zrotate(t_dpoint *point, t_dpoint *center, double angle)
{
	t_dpoint	pre;

	pre = setdpoint(point->x - center->x, point->y - center->y, point->z);
	point->x = pre.x * cos(angle) - pre.y * sin(angle) + center->x;
	point->y = pre.x * sin(angle) + pre.y * cos(angle) + center->y;
	point->z = pre.z;
}
