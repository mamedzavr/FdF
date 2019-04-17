/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:24:36 by gdaniel           #+#    #+#             */
/*   Updated: 2019/01/07 13:35:26 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

t_window	*createwindow(void *mlx_ptr, int size_x, int size_y, char *title)
{
	t_window *result;

	result = NULL;
	if (mlx_ptr != NULL)
	{
		if (!(result = (t_window*)malloc(sizeof(t_window))))
			return (result);
		result->mlx_ptr = mlx_ptr;
		result->size_x = size_x;
		result->size_y = size_y;
		result->title = title;
		result->window = mlx_new_window(mlx_ptr, size_x, size_y, title);
	}
	return (result);
}

void		editwindow(t_window **window, int size_x, int size_y, char *title)
{
	t_window *old;

	old = NULL;
	if (window != NULL)
	{
		old = window[0];
		if (!(window[0] = (t_window*)malloc(sizeof(t_window))))
			exit(EXIT_FAILURE);
		window[0]->mlx_ptr = old->mlx_ptr;
		window[0]->size_x = size_x;
		window[0]->size_y = size_y;
		window[0]->title = title;
		window[0]->window = mlx_new_window(window[0]->mlx_ptr,
		size_x, size_y, title);
	}
	if (old != NULL)
		mlx_destroy_window(old->mlx_ptr, old->window);
}
