/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:12:45 by obalagur          #+#    #+#             */
/*   Updated: 2018/04/07 13:12:47 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			deal_key(int key, t_frame *frame)
{
	if (key == ESC)
		terminate(frame, "");
	action_listener(key, frame);
	mlx_clear_window(frame->mlx, frame->win);
	draw_grid(frame);
	draw_menu(frame);
	return (0);
}

t_vortex3d	*get_end(t_frame *frame)
{
	t_vortex_group	*group_loop;
	t_vortex3d		*vort_loop;

	group_loop = frame->v_group;
	while (group_loop)
	{
		vort_loop = group_loop->vortex;
		while (vort_loop->next)
			vort_loop = vort_loop->next;
		group_loop = group_loop->next;
	}
	return (vort_loop);
}

t_vortex3d	*find_center(t_frame *frame)
{
	t_vortex3d	*end;
	t_vortex3d	*first;
	t_vortex3d	*center;

	end = get_end(frame);
	first = frame->v_group->vortex;
	if (frame->center)
		del_vortex(&(frame->center));
	center = set_vortex(CENTER(end->x, first->x), CENTER(end->y, first->y),
						CENTER(end->z, first->z), WHITE);
	return (center);
}

void		fit_scale(t_frame *frame)
{
	float h;
	float w;
	float max;

	w = (float)frame->size_x;
	h = (float)frame->size_y;
	max = fmax(w, h);
	if (max > 50)
		frame->scale_mult = 50 / max;
	else
		frame->scale_mult = 1;
}

void		render_window(t_frame *frame)
{
	int min_h;

	min_h = 0;
	frame->mlx = mlx_init();
	frame->rgb = 'n';
	frame->size_x = frame->v_group->size;
	frame->size_y = v_g_size(frame->v_group);
	fit_scale(frame);
	frame->width = ((frame->size_x - 1) * SCALE) + BORDER * 2;
	frame->height = ((frame->size_y - 1) * SCALE) + BORDER * 2;
	min_h = (((int)(350 - frame->height) > 0) ? (350 - frame->height) : 0);
	frame->win = mlx_new_window(frame->mlx,
				frame->width + 350, frame->height + min_h, " FDF ");
	set_scale(frame);
	frame->center = NULL;
	frame->center = find_center(frame);
	draw_grid(frame);
	draw_menu(frame);
	mlx_hook(frame->win, 2, 3, deal_key, frame);
	mlx_loop(frame->mlx);
}
