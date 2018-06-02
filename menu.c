/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:44:56 by obalagur          #+#    #+#             */
/*   Updated: 2018/05/19 15:44:58 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_menu_part1(t_frame *frame)
{
	mlx_string_put(frame->mlx, frame->win, frame->width, 25,\
		YELLOW, "Color template");
	mlx_string_put(frame->mlx, frame->win, frame->width, 50,\
		WHITE, "\t R : NumLock | G : / | B : *");
	mlx_string_put(frame->mlx, frame->win, frame->width, 75,\
		YELLOW, "Views");
	mlx_string_put(frame->mlx, frame->win, frame->width, 100,\
		WHITE, "\t TOP : 7 | SIDE : 8 | FRONT : 9");
	mlx_string_put(frame->mlx, frame->win, frame->width, 125,\
		WHITE, "\t ISO : 0");
}

static void		draw_menu_part2(t_frame *frame)
{
	mlx_string_put(frame->mlx, frame->win, frame->width, 150,\
		YELLOW, "Rotate");
	mlx_string_put(frame->mlx, frame->win, frame->width, 175,\
		WHITE, "\t x : 4 | y : 5 | z : 6");
	mlx_string_put(frame->mlx, frame->win, frame->width, 200,\
		WHITE, "\t     1 |     2 |     3");
	mlx_string_put(frame->mlx, frame->win, frame->width, 225,\
		YELLOW, "Scale");
	mlx_string_put(frame->mlx, frame->win, frame->width, 250,\
		WHITE, "\t INC : + | DEC : -");
}

static void		draw_menu_part3(t_frame *frame)
{
	mlx_string_put(frame->mlx, frame->win, frame->width, 275,\
		YELLOW, "MOVE");
	mlx_string_put(frame->mlx, frame->win, frame->width, 300,\
		WHITE, "\t x : UP   | y : LEFT");
	mlx_string_put(frame->mlx, frame->win, frame->width, 325,\
		WHITE, "\t     DOWN |     RIGHT");
}

void			draw_menu(t_frame *frame)
{
	draw_menu_part1(frame);
	draw_menu_part2(frame);
	draw_menu_part3(frame);
}
