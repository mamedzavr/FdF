/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:42:24 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:43:07 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

t_point		*createpointptr(int x, int y, int z)
{
	t_point *result;

	if (!(result = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}

t_fpoint	*createfpointptr(float x, float y, float z)
{
	t_fpoint *result;

	if (!(result = (t_fpoint*)malloc(sizeof(t_fpoint))))
		return (NULL);
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}

t_dpoint	*createdpointptr(double x, double y, double z)
{
	t_dpoint *result;

	if (!(result = (t_dpoint*)malloc(sizeof(t_dpoint))))
		return (NULL);
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}
