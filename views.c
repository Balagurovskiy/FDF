/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:27:40 by obalagur          #+#    #+#             */
/*   Updated: 2018/04/07 13:27:42 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_view(t_frame *frame, char flag, float step)
{
	step = 0.0;
	if (flag == 't')
		change_scale(frame, 'r', 0.0);
	else if (flag == 's')
	{
		change_scale(frame, 'r', 0.0);
		rotate(frame, 'x', -90.0f);
		rotate(frame, 'y', 90.0);
	}
	else if (flag == 'f')
	{
		change_scale(frame, 'r', 0.0);
		rotate(frame, 'x', -90.0f);
	}
	else if (flag == 'i')
	{
		change_scale(frame, 'r', 0.0);
		rotate(frame, 'x', -45.0f);
		rotate(frame, 'y', -35.0f);
		rotate(frame, 'z', 25.0f);
	}
}
