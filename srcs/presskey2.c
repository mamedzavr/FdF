/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presskey2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:51:05 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/06 18:32:32 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		isrotate(t_map map, int key)
{
	return (map.type == FREE && (key == 65363 || key == 65361
	|| key == 65362 || key == 65364 ||
	key == 113 || key == 101 || key == 123 || key == 124
	|| key == 126 || key == 125 || key == 12 || key == 14));
}

int		ismove(int key)
{
	if (key == 13 || key == 1 || key == 0 || key == 2 ||
	key == 119 || key == 115 || key == 97 || key == 100)
		return (1);
	return (0);
}
