/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vortex_group.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:27:40 by obalagur          #+#    #+#             */
/*   Updated: 2018/04/07 13:27:42 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					v_g_size(t_vortex_group *first_node)
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

t_vortex_group		*set_group(t_vortex3d *vortex3d)
{
	t_vortex_group	*new_node;

	if (!vortex3d)
		return (NULL);
	new_node = (t_vortex_group*)malloc(sizeof(t_vortex_group));
	if (new_node == NULL)
		return (NULL);
	new_node->vortex = vortex3d;
	new_node->size = v_size(vortex3d);
	new_node->next = NULL;
	return (new_node);
}

void				add_group(t_vortex_group **first_node,
							t_vortex_group *new_node)
{
	t_vortex_group *f;

	if (!new_node)
		return ;
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

void				del_group(t_vortex_group **alst)
{
	t_vortex_group *del_temp;

	if (*alst)
	{
		while (*alst)
		{
			del_vortex(&((*alst)->vortex));
			del_temp = *alst;
			*alst = (*alst)->next;
			free(del_temp);
			del_temp = NULL;
		}
	}
}
