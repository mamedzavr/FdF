/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextocolor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:50:33 by gdaniel           #+#    #+#             */
/*   Updated: 2019/04/17 17:38:23 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_hexcolor(t_rgbcolor *color, char *hexcord, int i)
{
	if (i == 8 || i == 7)
		*color = setcolor(atoi16(hexcord),
		atoi16(hexcord + 2), atoi16(hexcord + 4));
	if (i == 6 || i == 5)
		*color = setcolor(0, atoi16(hexcord),
		atoi16(hexcord + 2));
	if (i == 4 || i == 3)
		*color = setcolor(0, 0, atoi16(hexcord));
}

void		hex_to_color(t_rgbcolor *color, char *hexcord)
{
	short		i;
	short		x;

	i = 0;
	while (*hexcord)
	{
		if ((*hexcord >= '0' && *hexcord <= '9') ||
			(*hexcord >= 'A' && *hexcord <= 'F') ||
			(*hexcord >= 'a' && *hexcord <= 'f') ||
			(*hexcord == 'x') || (*hexcord == ','))
		{
			if (*hexcord == 'x')
				x = i + 1;
		}
		else
			error("Bad color");
		hexcord++;
		i++;
	}
	hexcord = hexcord - i + x;
	set_hexcolor(color, hexcord, i);
}
