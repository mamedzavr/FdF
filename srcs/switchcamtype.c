/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switchcamtype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:13:41 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/06 16:19:37 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	switchcamtype(t_fdf *fdf)
{
	fdf->map.type += 1;
	if (fdf->map.type > 2)
		fdf->map.type = 0;
	if (fdf->map.type == ISO)
	{
		copymaptoview(fdf);
		switchcolor(fdf, fdf->map.cmode);
		iso(fdf);
	}
	else if (fdf->map.type == PARALLE)
	{
		copymaptoview(fdf);
		switchcolor(fdf, fdf->map.cmode);
		cabinet(fdf);
	}
	else
	{
		copymaptoview(fdf);
		switchcolor(fdf, fdf->map.cmode);
	}
}
