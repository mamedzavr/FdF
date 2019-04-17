/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:22:46 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:40:24 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

int			ft_lerp(int start, int end, float t)
{
	return (start + t * (end - start));
}

t_rgbcolor	ft_lerpcolor(t_rgbcolor *start, t_rgbcolor *end, float t)
{
	t_rgbcolor result;

	if (start != NULL && end != NULL)
	{
		result.red = ft_lerp(start->red, end->red, t);
		result.green = ft_lerp(start->green, end->green, t);
		result.blue = ft_lerp(start->blue, end->blue, t);
		return (result);
	}
	return (setcolor(255, 255, 255));
}
