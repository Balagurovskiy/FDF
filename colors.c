/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:47:26 by obalagur          #+#    #+#             */
/*   Updated: 2018/05/19 15:47:28 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_red_template(t_frame *frame, int z)
{
	int colors[8];

	colors[0] = coral;
	colors[1] = lightcoral;
	colors[2] = tomato;
	colors[3] = orangered;
	colors[4] = red;
	colors[5] = hotpink;
	colors[6] = deeppink;
	colors[7] = pink;
	frame->rgb = 'r';
	return (colors[get_color_id(frame, z)]);
}

int			get_green_template(t_frame *frame, int z)
{
	int colors[8];

	colors[0] = darkgreen;
	colors[1] = darkseagreen;
	colors[2] = seagreen;
	colors[3] = lightseagreen;
	colors[4] = palegreen;
	colors[5] = springgreen;
	colors[6] = lawngreen;
	colors[7] = green;
	frame->rgb = 'g';
	return (colors[get_color_id(frame, z)]);
}

int			get_blue_template(t_frame *frame, int z)
{
	int colors[8];

	colors[0] = blue;
	colors[1] = deep_sky;
	colors[2] = skyblue;
	colors[3] = steelblue;
	colors[4] = lightblue;
	colors[5] = powderblue;
	colors[6] = turquoise;
	colors[7] = cyan;
	frame->rgb = 'b';
	return (colors[get_color_id(frame, z)]);
}

int			get_color_id(t_frame *frame, int z)
{
	int id;

	id = 0;
	if (z >= 0)
		id = (z / SCALE) / 5 + 4;
	else
		id = 4 + (z / SCALE) / 5;
	if (id > 7)
		return (7);
	if (id < 0)
		return (0);
	return (id);
}

void		colorize_by_z(t_frame *frame, char ort, float step)
{
	t_vortex_group	*group_loop;
	t_vortex3d		*vort_loop;
	float			z;

	group_loop = frame->v_group;
	step = 0.0;
	while (group_loop)
	{
		vort_loop = group_loop->vortex;
		while (vort_loop)
		{
			z = vort_loop->z0 * SCALE;
			if (ort == 'r')
				vort_loop->color = get_red_template(frame, z);
			else if (ort == 'g')
				vort_loop->color = get_green_template(frame, z);
			else if (ort == 'b')
				vort_loop->color = get_blue_template(frame, z);
			vort_loop = vort_loop->next;
		}
		group_loop = group_loop->next;
	}
}
