/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:45:25 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:39:55 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

t_rgbcolor	setcolor(int red, int green, int blue)
{
	t_rgbcolor	color;

	color.red = red;
	color.green = green;
	color.blue = blue;
	return (color);
}

void		setcolorptr(t_rgbcolor *color, int red, int green, int blue)
{
	if (color != NULL)
	{
		color->red = red;
		color->green = green;
		color->blue = blue;
	}
}
