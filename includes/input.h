/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaniel <gdaniel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:11:06 by gdaniel           #+#    #+#             */
/*   Updated: 2019/02/04 17:11:15 by gdaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H
# include "fdf.h"

void	update_input(t_fdf *fdf);
int		mouseclick(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
int		mousedown(int button, int x, int y, void *param);
int		mouseup(int button, int x, int y, void *param);
int		keyboarddown(int key, void *param);
void	clickcolor(void *param);
int		winclose(void *param);

#endif
