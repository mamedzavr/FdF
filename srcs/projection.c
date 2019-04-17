/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:58:46 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/06 15:59:38 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_fdf *fdf)
{
	t_point		cord;

	cord.y = 0;
	while (cord.y < fdf->map.size.y)
	{
		cord.x = 0;
		while (cord.x < fdf->map.size.x)
		{
			fdf->map.view[cord.y][cord.x].cord.z /= 4;
			zrotate(&fdf->map.view[cord.y][cord.x].cord,
			&fdf->map.center, -0.75f);
			xrotate(&fdf->map.view[cord.y][cord.x].cord, &fdf->map.center, 1);
			cord.x++;
		}
		cord.y++;
	}
}

void	cabinet(t_fdf *fdf)
{
	t_point pre;
	t_point cord;

	cord.y = 0;
	while (cord.y < fdf->map.size.y)
	{
		cord.x = 0;
		while (cord.x < fdf->map.size.x)
		{
			pre = setpoint(fdf->map.view[cord.y][cord.x].cord.x,
			fdf->map.view[cord.y][cord.x].cord.y,
			fdf->map.view[cord.y][cord.x].cord.z);
			fdf->map.view[cord.y][cord.x].cord.x =
			(pre.x - (pre.z / 2)) * cos(0.78);
			fdf->map.view[cord.y][cord.x].cord.y =
			(pre.y - (pre.z / 2)) * sin(0.78);
			cord.x++;
		}
		cord.y++;
	}
}
