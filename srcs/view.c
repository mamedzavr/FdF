/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:41:34 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/06 16:00:04 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		copymaptoview(t_fdf *fdf)
{
	t_point cord;

	cord.y = 0;
	while (cord.y < fdf->map.size.y)
	{
		cord.x = 0;
		while (cord.x < fdf->map.size.x)
		{
			fdf->map.view[cord.y][cord.x] = fdf->map.map[cord.y][cord.x];
			cord.x++;
		}
		cord.y++;
	}
}

t_mappoint	**createview(t_map map)
{
	t_mappoint	**view;
	int			y;

	if (!(view = (t_mappoint**)malloc(sizeof(t_mappoint*) * map.size.y)))
		error("Memory is not allocated");
	y = 0;
	while (y < map.size.y)
	{
		if (!(view[y] = (t_mappoint*)malloc(sizeof(t_mappoint) * map.size.x)))
			error("Memory is not allocated");
		y++;
	}
	return (view);
}

void		foto(t_fdf *fdf)
{
	t_point	cord;

	cord.y = 0;
	while (cord.y < fdf->map.size.y)
	{
		cord.x = 0;
		while (cord.x < fdf->map.size.x)
		{
			fdf->map.view[cord.y][cord.x].cord.z = 0;
			cord.x++;
		}
		cord.y++;
	}
}
