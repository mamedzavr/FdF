/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouseclick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:58:51 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 16:58:52 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int		mouseclick(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	x++;
	y++;
	if (button == 4 || button == 5)
	{
		if (button == 4)
			fdf->cellsize += 1;
		if (button == 5)
			if (fdf->cellsize > 1)
				fdf->cellsize -= 1;
	}
	draw(fdf);
	return (0);
}
