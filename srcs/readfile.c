/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:38:54 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/04/17 17:38:39 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			find_depth(t_map *tmap)
{
	t_point		cord;
	double		min;
	double		max;

	cord.y = 0;
	min = tmap->map[0][0].cord.z;
	max = tmap->map[0][0].cord.z;
	while (cord.y < tmap->size.y)
	{
		cord.x = 0;
		while (cord.x < tmap->size.x)
		{
			tmap->map[cord.y][cord.x].cord.z < min ?
				min = tmap->map[cord.y][cord.x].cord.z : 0;
			tmap->map[cord.y][cord.x].cord.z > max ?
				max = tmap->map[cord.y][cord.x].cord.z : 0;
			cord.x++;
		}
		cord.y++;
	}
	tmap->max = max;
	tmap->min = min;
}

int					regcolor(char **isplit, t_mappoint **cm, t_point *cord)
{
	char		**numbercolor;

	numbercolor = ft_strsplit(isplit[cord->x], ',');
	if (ft_strstr(isplit[cord->x], ",0x") != NULL)
		hex_to_color(&cm[cord->y][cord->x].defaultcolor, numbercolor[1]);
	else
		cm[cord->y][cord->x].defaultcolor = setcolor(255, 255, 255);
	cm[cord->y][cord->x].cord =
		setdpoint(cord->x, cord->y, ft_atoi(numbercolor[0]));
	delete_map(numbercolor);
	return (1);
}

static t_mappoint	**fillcord(char **split, int linecount, int wordcount)
{
	t_point		cord;
	char		**isplit;
	t_mappoint	**cm;

	cord.y = 0;
	if (!(cm = (t_mappoint**)malloc(sizeof(t_mappoint*) * linecount)))
		error("Memory is not allocated");
	while (cord.y < linecount)
	{
		cord.x = -1;
		isplit = ft_strsplit(split[cord.y], ' ');
		cm[cord.y] = (t_mappoint*)malloc(sizeof(t_mappoint) * wordcount);
		while (++cord.x < wordcount)
			regcolor(isplit, cm, &cord);
		cord.y++;
	}
	delete_map(split) == 1 ? delete_map(isplit) : 0;
	return (cm);
}

static	t_mappoint	**givemap(int fd, t_map *tmap)
{
	char		*string[4];
	char		**split;
	int			linewordcount[2];
	int			words;
	int			flag;

	flag = 0;
	string[0] = ft_strnew(1);
	linewordcount[0] = 0;
	while (get_next_line(fd, &string[2]) == 1)
	{
		if (flag == 0)
		{
			words = ft_wordcount(string[2], ' ');
			flag++;
		}
		crutch(string, linewordcount, words);
	}
	flag == 0 ? error("Empty file") : 0;
	split = ft_strsplit(string[0], '\n');
	ft_strdel(&string[0]);
	tmap->size = setpoint(linewordcount[1], linewordcount[0], 0);
	return (fillcord(split, linewordcount[0], linewordcount[1]));
}

t_map				readfile(int fd)
{
	t_map	tmap;

	tmap.map = givemap(fd, &tmap);
	find_depth(&tmap);
	return (tmap);
}
