/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_listener.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:38:05 by obalagur          #+#    #+#             */
/*   Updated: 2018/04/27 19:38:08 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_actions			*action_container(void)
{
	t_actions *a;

	a = new_action(&move, UP, 'y', -10.0);
	add_action(&a, new_action(&move, DOWN, 'y', 10.0f));
	add_action(&a, new_action(&move, LEFT, 'x', -10.0f));
	add_action(&a, new_action(&move, RIGHT, 'x', 10.0f));
	add_action(&a, new_action(&rotate, ROT_X_4, 'x', 2.0f));
	add_action(&a, new_action(&rotate, ROT_X_1, 'x', -2.0f));
	add_action(&a, new_action(&rotate, ROT_Y_5, 'y', 2.0f));
	add_action(&a, new_action(&rotate, ROT_Y_2, 'y', -2.0f));
	add_action(&a, new_action(&rotate, ROT_Z_6, 'z', 2.0f));
	add_action(&a, new_action(&rotate, ROT_Z_3, 'z', -2.0f));
	add_action(&a, new_action(&change_scale, ZOOM_IN, '+', 0.02f));
	add_action(&a, new_action(&change_scale, ZOOM_OUT, '-', 0.02f));
	add_action(&a, new_action(&set_view, TOP_7, 't', 0.0));
	add_action(&a, new_action(&set_view, SIDE_8, 's', 0.0));
	add_action(&a, new_action(&set_view, FACE_9, 'f', 0.0));
	add_action(&a, new_action(&set_view, ISO_0, 'i', 0.0));
	add_action(&a, new_action(&colorize_by_z, COLOR_R, 'r', 0.0));
	add_action(&a, new_action(&colorize_by_z, COLOR_G, 'g', 0.0));
	add_action(&a, new_action(&colorize_by_z, COLOR_B, 'b', 0.0));
	return (a);
}

t_actions			*find_action(int key, t_actions *actions)
{
	t_actions *a;

	a = actions;
	while (a)
	{
		if (key == a->key)
			return (a);
		a = a->next;
	}
	return (NULL);
}

void				action_listener(int key, t_frame *frame)
{
	t_actions	*action;
	void		(*action_fun)(t_frame *, char, float);

	action = find_action(key, frame->actions);
	if (action)
	{
		action_fun = (void (*)(t_frame *, char, float))action->fun;
		(*action_fun)(frame, action->flag, action->step);
	}
}
