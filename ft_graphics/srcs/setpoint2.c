/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpoint2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:43:39 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:43:57 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

t_dpoint	setdpoint(double x, double y, double z)
{
	t_dpoint result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

void		setdpointptr(t_dpoint *point, double x, double y, double z)
{
	if (point != NULL)
	{
		point->x = x;
		point->y = y;
		point->z = z;
	}
}
