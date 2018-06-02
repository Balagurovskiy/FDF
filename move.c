/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:38:05 by obalagur          #+#    #+#             */
/*   Updated: 2018/04/27 19:38:08 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move(t_frame *frame, char direction, float step)
{
	t_vortex_group	*v_g;
	t_vortex3d		*v;

	v_g = frame->v_group;
	while (v_g)
	{
		v = v_g->vortex;
		while (v)
		{
			if (direction == 'x')
				v->x += step;
			else if (direction == 'y')
				v->y += step;
			else if (direction == 'z')
				v->z += step;
			v = v->next;
		}
		v_g = v_g->next;
	}
}

void		move_to_start(t_frame *frame)
{
	t_vortex_group	*v_g;
	t_vortex3d		*v;

	v_g = frame->v_group;
	while (v_g)
	{
		v = v_g->vortex;
		while (v)
		{
			v->x = v->x0 * SCALE;
			v->y = v->y0 * SCALE;
			v->z = v->z0 * SCALE;
			v = v->next;
		}
		v_g = v_g->next;
	}
}
