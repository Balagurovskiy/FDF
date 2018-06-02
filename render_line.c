/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:54:53 by obalagur          #+#    #+#             */
/*   Updated: 2018/04/09 14:54:55 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line		*set_line(t_vortex3d *v0, t_vortex3d *v1)
{
	t_line *l;

	l = (t_line *)malloc(sizeof(t_line));
	if (!l)
		return (NULL);
	l->dx = fabs(v1->x - v0->x);
	l->sx = ((v0->x < v1->x) ? 1.0 : -1.0);
	l->dy = fabs(v1->y - v0->y);
	l->sy = ((v0->y < v1->y) ? 1.0 : -1.0);
	l->err = l->dx - l->dy;
	l->x0 = v0->x;
	l->x1 = v1->x;
	l->y0 = v0->y;
	l->y1 = v1->y;
	l->dist = DIST(v1->x, v0->x, v1->y, v0->y);
	return (l);
}

int			colorize(t_line *l, t_vortex3d *v0, t_vortex3d *v1)
{
	float curr_dist;

	if (v0->color == v1->color)
		return (v0->color);
	else
	{
		curr_dist = DIST(l->x1, l->x0, l->y1, l->y0);
		if ((l->dist / 2) < curr_dist)
			return (v0->color);
		else
			return (v1->color);
	}
	return (WHITE);
}

void		draw_line(t_frame *frame, t_vortex3d *v0, t_vortex3d *v1)
{
	t_line	*l;
	float	e2;

	l = set_line(v0, v1);
	if (!l)
		return ;
	while (fabs(l->x0 - l->x1) >= 1 || fabs(l->y0 - l->y1) >= 1)
	{
		mlx_pixel_put(frame->mlx, frame->win,
				DELTA_X + l->x0, DELTA_Y + l->y0, colorize(l, v0, v1));
		e2 = 2.0 * l->err;
		if (e2 > -l->dy)
		{
			l->err -= l->dy;
			l->x0 += l->sx;
		}
		if (e2 < l->dx)
		{
			l->err += l->dx;
			l->y0 += l->sy;
		}
	}
	if (l)
		free(l);
}

void		draw_grid(t_frame *frame)
{
	t_vortex_group	*v_g_temp;
	t_vortex3d		*v;

	v_g_temp = frame->v_group;
	while (v_g_temp)
	{
		v = v_g_temp->vortex;
		while (v)
		{
			if (v->next)
				draw_line(frame, v, v->next);
			if (v->next_v)
				draw_line(frame, v, v->next_v);
			v = v->next;
		}
		v_g_temp = v_g_temp->next;
	}
}
