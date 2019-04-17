/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpoint1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:24:11 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:43:51 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

t_point		setpoint(int x, int y, int z)
{
	t_point result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

void		setpointptr(t_point *point, int x, int y, int z)
{
	if (point != NULL)
	{
		point->x = x;
		point->y = y;
		point->z = z;
	}
}

t_fpoint	setfpoint(float x, float y, float z)
{
	t_fpoint result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

void		setfpointptr(t_fpoint *point, float x, float y, float z)
{
	if (point != NULL)
	{
		point->x = x;
		point->y = y;
		point->z = z;
	}
}
