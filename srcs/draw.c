/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:24:29 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 15:07:44 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw(t_fdf *fdf)
{
	mlx_clear_window(fdf->window->mlx_ptr, fdf->window->window);
	clearimage(fdf->image);
	drawmap(fdf);
	mlx_put_image_to_window(fdf->window->mlx_ptr, fdf->window->window,
	fdf->image->img_ptr, 0, 0);
	drawui(fdf);
}
