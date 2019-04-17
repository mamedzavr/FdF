/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multpoint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:44:28 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:31:42 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

t_dpoint		multdpoint(t_dpoint point, double x, double y, double z)
{
	point.x *= x;
	point.y *= y;
	point.z *= z;
	return (point);
}
