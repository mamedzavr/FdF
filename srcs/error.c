/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:34:49 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/05 11:27:22 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage(char *argv1)
{
	ft_putstr("Usage: ");
	ft_putstr(argv1);
	ft_putendl(" file color1 color2 color3 color4 color5");
	ft_putendl("color format: 255,255,255");
	exit(EXIT_FAILURE);
}

void	error(char *str)
{
	if (str != NULL)
		ft_putendl(str);
	exit(EXIT_FAILURE);
}
