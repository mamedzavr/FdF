/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:41:35 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:40:09 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

t_rgbcolor	*createcolor(int red, int green, int blue)
{
	t_rgbcolor *result;

	if (!(result = (t_rgbcolor*)malloc(sizeof(t_rgbcolor))))
		return (NULL);
	result->red = red;
	result->green = green;
	result->blue = blue;
	return (result);
}
