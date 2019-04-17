/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switchcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:58:10 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/06 15:58:21 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	switchcolor(t_fdf *fdf, int mode)
{
	t_point	cord;

	cord.y = 0;
	while (cord.y < fdf->map.size.y)
	{
		cord.x = 0;
		while (cord.x < fdf->map.size.x)
		{
			if (mode == 1)
				fdf->map.view[cord.y][cord.x].vcolor =
				&fdf->map.map[cord.y][cord.x].customcolor;
			else
				fdf->map.view[cord.y][cord.x].vcolor =
				&fdf->map.map[cord.y][cord.x].defaultcolor;
			cord.x++;
		}
		cord.y++;
	}
}
