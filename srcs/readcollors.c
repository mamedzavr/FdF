/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readcollors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:10:24 by gdaniel           #+#    #+#             */
/*   Updated: 2019/04/17 17:38:37 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			crutch(char **str, int *linewordcount, int words)
{
	str[3] = str[0];
	str[1] = ft_strjoin(str[2], "\n");
	str[0] = ft_strjoin(str[0], str[1]);
	linewordcount[1] = ft_wordcount(str[2], ' ');
	(linewordcount[1] == words) ? linewordcount[0]++ :
		error("Found wrong line length. Exiting.");
	ft_strdel(&str[1]);
	ft_strdel(&str[2]);
	ft_strdel(&str[3]);
	return (1);
}

short		atoi16(char *num)
{
	short		letter1;
	short		letter2;

	letter1 = 0;
	letter2 = 0;
	if (*num >= '0' && *num <= '9')
		letter1 = (int)*num - 48;
	else if (*num >= 'A' && *num <= 'F')
		letter1 = (int)*num - 55;
	else if (*num >= 'a' && *num <= 'f')
		letter1 = (int)*num - 87;
	num++;
	if (*num >= '0' && *num <= '9')
		letter2 = (int)*num - 48;
	else if (*num >= 'A' && *num <= 'F')
		letter2 = (int)*num - 55;
	else if (*num >= 'a' && *num <= 'f')
		letter2 = (int)*num - 87;
	return (16 * letter1 + letter2);
}

int			delete_map(char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		ft_strdel(&split[i]);
		i++;
	}
	return (1);
}

void		checkreadcolor(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			error("Bad color");
		i++;
	}
}

void		readcollors(t_fdf *fdf, char **argv)
{
	t_point	cord;
	int		len;
	char	**split;

	cord.y = 0;
	while (cord.y < 5)
	{
		cord.x = 0;
		if (ft_wordcount(argv[cord.y + 2], ',') != 3)
			error("Bad color");
		split = ft_strsplit(argv[cord.y + 2], ',');
		while (cord.x < 3)
		{
			len = ft_strlen(argv[cord.y + 2]);
			if (len < 1 && len > 3)
				error("Bad color");
			checkreadcolor(split[cord.x]);
			cord.x++;
		}
		fdf->map.color[cord.y] = setcolor(ft_atoi(split[0]),
		ft_atoi(split[1]), ft_atoi(split[2]));
		delete_map(split);
		cord.y++;
	}
}
