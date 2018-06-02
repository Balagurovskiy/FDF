/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:38:05 by obalagur          #+#    #+#             */
/*   Updated: 2018/04/27 19:38:08 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_matrix(t_vortex3d *v, float step, char ort)
{
	float yy;
	float xx;

	if (ort == 'x')
	{
		yy = ((v->y * COS(step)) + (v->z * SIN(step)));
		v->z = ((-v->y * SIN(step)) + (v->z * COS(step)));
		v->y = yy;
	}
	else if (ort == 'y')
	{
		xx = ((v->x * COS(step)) + (v->z * SIN(step)));
		v->z = ((-v->x * SIN(step)) + (v->z * COS(step)));
		v->x = xx;
	}
	else if (ort == 'z')
	{
		xx = ((v->x * COS(step)) - (v->y * SIN(step)));
		v->y = ((v->x * SIN(step)) + (v->y * COS(step)));
		v->x = xx;
	}
}

void		rotate(t_frame *frame, char ort, float step)
{
	t_vortex_group	*group_loop;
	t_vortex3d		*vort_loop;

	group_loop = frame->v_group;
	frame->center = find_center(frame);
	while (group_loop)
	{
		vort_loop = group_loop->vortex;
		while (vort_loop)
		{
			vort_loop->x -= frame->center->x0;
			vort_loop->y -= frame->center->y0;
			vort_loop->z -= frame->center->z0;
			rotate_matrix(vort_loop, step, ort);
			vort_loop->x += frame->center->x0;
			vort_loop->y += frame->center->y0;
			vort_loop->z += frame->center->z0;
			vort_loop = vort_loop->next;
		}
		group_loop = group_loop->next;
	}
}
