/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmappoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:43:35 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 18:43:42 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mappoint	setmappoint(t_dpoint po, t_rgbcolor color)
{
	t_mappoint	point;

	point.cord = po;
	point.defaultcolor = color;
	return (point);
}
