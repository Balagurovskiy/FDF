/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:27:40 by obalagur          #+#    #+#             */
/*   Updated: 2018/04/07 13:27:42 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_actions		*new_action(void (*fun)(t_frame *, char, float),
							int key, char flag, float step)
{
	t_actions	*new_node;

	new_node = (t_actions*)malloc(sizeof(t_actions));
	if (new_node == NULL)
		return (NULL);
	new_node->fun = (void (*)())fun;
	new_node->key = key;
	new_node->flag = flag;
	new_node->step = step;
	new_node->next = NULL;
	return (new_node);
}

void			add_action(t_actions **first_node, t_actions *new_node)
{
	t_actions *f;

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

void			del_action(t_actions **alst)
{
	t_actions *del_temp;

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
