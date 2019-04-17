/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:59:04 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 16:59:05 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int		winclose(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	update_input(t_fdf *fdf)
{
	mlx_mouse_hook(fdf->window->window, mouseclick, fdf);
	mlx_hook(fdf->window->window, 17, 1, winclose, (void*)0);
	mlx_hook(fdf->window->window, 2, 3, keyboarddown, fdf);
}
