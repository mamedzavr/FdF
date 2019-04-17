/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:53:56 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:40:31 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

void	put_pixel_to_image(t_image *img, t_point cord, t_rgbcolor color)
{
	int	*i;

	i = (int*)img->line;
	if (cord.x > 0 && cord.y > 0 &&
	cord.x < img->size.x && cord.y < img->size.y)
		i[cord.x + (cord.y * img->size.x)] = convertcolor(color);
}
