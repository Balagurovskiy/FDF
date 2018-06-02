/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:38:05 by obalagur          #+#    #+#             */
/*   Updated: 2018/04/27 19:38:08 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		change_scale(t_frame *frame, char flag, float step)
{
	if (flag == '+')
	{
		frame->scale_mult += step;
		set_scale(frame);
	}
	else if (flag == '-')
	{
		frame->scale_mult -= step;
		if (frame->scale_mult < 0)
			frame->scale_mult = 0.0;
		set_scale(frame);
	}
	else if (flag == 'r')
	{
		set_scale(frame);
		move_to_start(frame);
	}
}

void		rescale(t_frame *frame, t_vortex3d *v, float save)
{
	v->x = v->x / save;
	v->y = v->y / save;
	if (save != 1.0)
		v->z = v->z / save;
	v->x = v->x * SCALE;
	v->y = v->y * SCALE;
	v->z = v->z * SCALE;
}

void		set_scale(t_frame *frame)
{
	t_vortex_group	*v_g;
	t_vortex3d		*v;
	static	float	scale_save = 1.0;

	v_g = frame->v_group;
	while (v_g)
	{
		v = v_g->vortex;
		while (v)
		{
			rescale(frame, v, scale_save);
			v = v->next;
		}
		v_g = v_g->next;
	}
	scale_save = SCALE;
}
