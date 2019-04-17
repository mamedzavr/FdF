/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createrect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:42:08 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:32:32 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

t_rect		*createrectptr(t_point *start, int height, int width)
{
	t_rect *result;

	result = NULL;
	if (start != NULL)
	{
		if (!(result = (t_rect*)malloc(sizeof(t_rect))))
			return (result);
		result->start = start;
		result->height = height;
		result->width = width;
	}
	return (result);
}

t_frect		*createfrectptr(t_fpoint *start, float height, float width)
{
	t_frect *result;

	result = NULL;
	if (start != NULL)
	{
		if (!(result = (t_frect*)malloc(sizeof(t_frect))))
			return (result);
		result->start = start;
		result->height = height;
		result->width = width;
	}
	return (result);
}
