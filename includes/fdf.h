/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:40:08 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/02/06 16:05:00 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include "../ft_graphics/includes/ft_graphics.h"
# include "../libft/libft.h"

typedef struct	s_mappoint
{
	t_dpoint	cord;
	t_rgbcolor	*vcolor;
	t_rgbcolor	defaultcolor;
	t_rgbcolor	customcolor;
}				t_mappoint;
enum	e_camtype
{
	ISO,
	PARALLE,
	FREE
}		camtype;
typedef struct	s_map
{
	t_mappoint		**map;
	t_mappoint		**view;
	t_point			size;
	enum e_camtype	type;
	int				max;
	int				min;
	int				cmode;
	t_dpoint		center;
	t_dpoint		drawcenter;
	t_rgbcolor		color[5];
}				t_map;
typedef struct	s_camera
{
	t_point				cord;
	t_dpoint			angle;
	int					camz;
	int					speed;
}				t_camera;
typedef struct	s_fdf
{
	t_window	*window;
	t_image		*image;
	t_camera	cam;
	t_map		map;
	int			cellsize;
}				t_fdf;
void			update(t_fdf *fdf);
void			draw(t_fdf *fdf);
void			error(char *str);
void			usage(char *argv1);
t_map			readfile(int fd);
void			readcollors(t_fdf *fdf, char **argv);
t_mappoint		setmappoint(t_dpoint po, t_rgbcolor color);
void			drawlinelerp(t_fdf *fdf, t_mappoint start, t_mappoint end);
void			switchcamtype(t_fdf *fdf);
void			switchcolor(t_fdf *fdf, int mode);
void			colormap(t_fdf *fdf);
void			drawmap(t_fdf *fdf);
void			drawui(t_fdf *fdf);
void			iso(t_fdf *fdf);
void			cabinet(t_fdf *fdf);
void			fdfrotate(t_fdf *fdf);
void			foto(t_fdf *fdf);
int				delete_map(char **split);
void			readcollors(t_fdf *fdf, char **argv);
short			atoi16(char *num);
int				isrotate(t_map map, int key);
int				ismove(int key);
int				crutch(char **str, int *linewordcount, int words);
t_mappoint		**createview(t_map map);
void			copymaptoview(t_fdf *fdf);
int				regcolor(char **isplit, t_mappoint **cm, t_point *cord);
void			hex_to_color(t_rgbcolor *color, char *hexcord);

#endif
