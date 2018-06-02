/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vortex3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:27:40 by obalagur          #+#    #+#             */
/*   Updated: 2018/04/07 13:27:42 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				v_size(t_vortex3d *first_node)
{
	int i;

	i = 0;
	if (first_node)
	{
		while (first_node != NULL)
		{
			first_node = first_node->next;
			i++;
		}
	}
	return (i);
}

t_vortex3d		*set_vortex(int x, int y, int z, int color)
{
	t_vortex3d	*new_node;

	new_node = (t_vortex3d*)malloc(sizeof(t_vortex3d));
	if (new_node == NULL)
		return (NULL);
	new_node->x0 = (float)x;
	new_node->y0 = (float)y;
	new_node->z0 = (float)z;
	new_node->x = (float)x;
	new_node->y = (float)y;
	new_node->z = (float)z;
	new_node->color = color;
	new_node->next = NULL;
	new_node->next_v = NULL;
	return (new_node);
}

void			add_vortex(t_vortex3d **first_node, t_vortex3d *new_node)
{
	t_vortex3d *f;

	if (*first_node != NULL)
	{
		f = *first_node;
		while (f)
		{
			if (f->next == NULL)
			{
				f->next = new_node;
				break ;
			}
			f = f->next;
		}
	}
	else
		*first_node = new_node;
}

void			del_vortex(t_vortex3d **alst)
{
	t_vortex3d *del_temp;

	if (*alst)
	{
		while (*alst)
		{
			del_temp = *alst;
			*alst = (*alst)->next;
			free(del_temp);
			del_temp = NULL;
		}
	}
}
