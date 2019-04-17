/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:47:18 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/02/04 18:42:22 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHICS_H
# define FT_GRAPHICS_H
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*window;
	int			size_x;
	int			size_y;
	char		*title;
}				t_window;
t_window		*createwindow(void *mlx_ptr, int size_x, int size_y,
char *title);
void			editwindow(t_window **window, int size_x, int size_y,
char *title);
typedef struct	s_point
{
	int x;
	int y;
	int z;
}				t_point;
t_point			*createpointptr(int x, int y, int z);
t_point			setpoint(int x, int y, int z);
void			setpointptr(t_point *point, int x, int y, int z);
void			plusepointptr(t_point *point, int x, int y, int z);
t_point			plusepoint(t_point p, int x, int y, int z);

typedef struct	s_rect
{
	t_point	*start;
	int		height;
	int		width;
}				t_rect;
t_rect			*createrectptr(t_point *start, int height, int width);
t_rect			setrect(t_point start, int height, int width);
void			setrectptr(t_rect *rect, t_point *start, int height, int width);
typedef struct	s_fpoint
{
	float x;
	float y;
	float z;
}				t_fpoint;
t_fpoint		*createfpointptr(float x, float y, float z);
t_fpoint		setfpoint(float x, float y, float z);
void			setfpointptr(t_fpoint *point, float x, float y, float z);
typedef struct	s_frect
{
	t_fpoint	*start;
	float		height;
	float		width;
}				t_frect;
t_frect			*createfrectptr(t_fpoint *start, float height, float width);
t_frect			setfrect(t_fpoint start, float height, float width);
void			setfrectptr(t_frect *rect, t_fpoint *start, float height,
float width);
typedef struct	s_dpoint
{
	double x;
	double y;
	double z;
}				t_dpoint;
t_dpoint		*createdpointptr(double x, double y, double z);
t_dpoint		setdpoint(double x, double y, double z);
void			setdpointptr(t_dpoint *point, double x, double y, double z);
t_dpoint		plusedpoint(t_dpoint point, double x, double y, double z);
t_dpoint		minusdpoint(t_dpoint point, double x, double y, double z);
t_dpoint		multdpoint(t_dpoint point, double x, double y, double z);
int				point2rectcollision(t_point point, t_rect rect);
int				rect2rectcollision(t_rect *start, t_rect *end);
typedef struct	s_rgbcolor
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
}				t_rgbcolor;
t_rgbcolor		*createcolor(int red, int green, int blue);
t_rgbcolor		setcolor(int red, int green, int blue);
void			setcolorptr(t_rgbcolor *color, int red, int green, int blue);
int				convertcolorptr(t_rgbcolor *color);
int				convertcolor(t_rgbcolor color);
t_rgbcolor		ft_lerpcolor(t_rgbcolor *start, t_rgbcolor *end, float t);
typedef struct	s_image
{
	void	*img_ptr;
	t_point	size;
	char	*line;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;
t_image			*createimage(void *mlx, t_point size);
void			resizeimage(void *mlx, t_image **img, t_point newsize);
void			clearimage(t_image *img);
void			put_pixel_to_image(t_image *img, t_point cord,
t_rgbcolor color);
void			xrotate(t_dpoint	*point, t_dpoint *center, double angle);
void			yrotate(t_dpoint	*point, t_dpoint *center, double angle);
void			zrotate(t_dpoint	*point, t_dpoint *center, double angle);
void			drawline(t_image *img, t_dpoint start, t_dpoint end,
t_rgbcolor color);
void			drawrect(t_image *img, t_rect *rect, t_rgbcolor color);
#endif
