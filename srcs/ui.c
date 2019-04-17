/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:20:26 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/06 18:55:21 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawui(t_fdf *fdf)
{
	mlx_string_put(fdf->window->mlx_ptr, fdf->window->window, 10, 10,
	0x00FFFFFF, "Rotate: Arrow & Q, E");
	mlx_string_put(fdf->window->mlx_ptr, fdf->window->window, 10, 25,
	0x00FFFFFF, "Move: W A S D");
	mlx_string_put(fdf->window->mlx_ptr, fdf->window->window, 10, 40,
	0x00FFFFFF, "Size: plus minus mousewheel");
	mlx_string_put(fdf->window->mlx_ptr, fdf->window->window, 10, 55,
	0x00FFFFFF, "Color: C");
	mlx_string_put(fdf->window->mlx_ptr, fdf->window->window, 10, 70,
	0x00FFFFFF, "Projection: T");
}
