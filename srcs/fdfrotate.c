/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:55:01 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/05 17:38:03 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdfrotate(t_fdf *fdf)
{
	t_point	cord;

	cord.y = 0;
	while (cord.y < fdf->map.size.y)
	{
		cord.x = 0;
		while (cord.x < fdf->map.size.x)
		{
			fdf->cam.angle.x != 0 ? xrotate(&fdf->map.view[cord.y][cord.x].cord,
			&fdf->map.center, fdf->cam.angle.x) : 0;
			fdf->cam.angle.y != 0 ? yrotate(&fdf->map.view[cord.y][cord.x].cord,
			&fdf->map.center, fdf->cam.angle.y) : 0;
			fdf->cam.angle.z != 0 ? zrotate(&fdf->map.view[cord.y][cord.x].cord,
			&fdf->map.center, fdf->cam.angle.z) : 0;
			cord.x++;
		}
		cord.y++;
	}
}
