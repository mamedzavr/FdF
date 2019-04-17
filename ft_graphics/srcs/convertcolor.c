/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertcolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:46:03 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:40:40 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

int			convertcolorptr(t_rgbcolor *color)
{
	if (color != NULL)
		return (color->red << 16 | color->green << 8 | color->blue);
	return (0x00FFFFFF);
}

int			convertcolor(t_rgbcolor color)
{
	return (color.red << 16 | color.green << 8 | color.blue);
}
