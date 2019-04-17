/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:30:52 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:42:24 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

t_image	*createimage(void *mlx, t_point size)
{
	t_image	*result;

	if (!(result = (t_image*)malloc(sizeof(t_image))))
		return (NULL);
	result->img_ptr = mlx_new_image(mlx, size.x, size.y);
	result->line = mlx_get_data_addr(result->img_ptr, &result->bpp,
	&result->size_line, &result->endian);
	result->size = size;
	return (result);
}

void	resizeimage(void *mlx, t_image **img, t_point newsize)
{
	void	*img_ptr;

	img_ptr = img[0]->img_ptr;
	img[0] = createimage(mlx, newsize);
	mlx_destroy_image(mlx, img_ptr);
}

void	clearimage(t_image *img)
{
	t_point	cord;
	int		*convert;

	if (img == NULL)
		return ;
	cord.y = 0;
	convert = (int*)img->line;
	while (cord.y < img->size.y)
	{
		cord.x = 0;
		while (cord.x < img->size.x)
		{
			convert[cord.x + (cord.y * img->size.x)] = 0x00000000;
			cord.x++;
		}
		cord.y++;
	}
}
