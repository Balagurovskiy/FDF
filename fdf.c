/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:16:19 by obalagur          #+#    #+#             */
/*   Updated: 2018/04/07 13:16:21 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	terminate(t_frame *frame, char *msg)
{
	if (ft_strlen(msg) > 1)
	{
		ft_putstr("fdf : ");
		ft_putstr(msg);
		ft_putstr("\n");
	}
	if (frame)
	{
		if (frame->v_group)
			del_group(&(frame->v_group));
		if (frame->actions)
			del_action(&(frame->actions));
		if (frame->center)
			del_vortex(&(frame->center));
		free(frame);
		frame = NULL;
	}
	exit(0);
}

void	size_validator(t_frame *frame)
{
	t_vortex_group	*v_g_1;
	t_vortex_group	*v_g_2;

	v_g_1 = frame->v_group;
	while (v_g_1)
	{
		v_g_2 = frame->v_group;
		while (v_g_2)
		{
			if (v_g_1->size != v_g_2->size)
				terminate(frame, "exception -> wrong data size");
			v_g_2 = v_g_2->next;
		}
		v_g_1 = v_g_1->next;
	}
}

int		main(int argc, char **argv)
{
	t_frame	*frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
	if (frame && argc == 2)
	{
		frame->actions = NULL;
		frame->center = NULL;
		frame->v_group = read_file(argv[1]);
		if (frame->v_group)
		{
			size_validator(frame);
			frame->actions = action_container();
			render_window(frame);
		}
		terminate(frame, "");
	}
	else
		ft_putstr("fdf : exception -> empty input\n");
	return (0);
}
