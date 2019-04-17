/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setrect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:41:43 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:41:48 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

t_rect		setrect(t_point start, int height, int width)
{
	t_rect result;

	result.start = &start;
	result.height = height;
	result.width = width;
	return (result);
}

void		setrectptr(t_rect *rect, t_point *start, int height, int width)
{
	if (rect != NULL)
	{
		rect->start = start;
		rect->height = height;
		rect->width = width;
	}
}

t_frect		setfrect(t_fpoint start, float height, float width)
{
	t_frect result;

	result.start = &start;
	result.height = height;
	result.width = width;
	return (result);
}

void		setfrectptr(t_frect *rect, t_fpoint *start, float height,
float width)
{
	if (rect != NULL)
	{
		rect->start = start;
		rect->height = height;
		rect->width = width;
	}
}
