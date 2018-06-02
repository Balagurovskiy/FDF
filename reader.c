/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:43:32 by obalagur          #+#    #+#             */
/*   Updated: 2018/03/31 15:43:38 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vortex_group	*make_vortex_group(char *line)
{
	t_vortex_group static	*v_g = NULL;

	add_group(&v_g, set_group(make_vortex(line)));
	return (v_g);
}

void			split_lines(char **splited_line, t_vortex3d **v, int entry)
{
	int			color;
	int			num;
	int			x;
	static int	check_x = 0;

	x = 0;
	color = WHITE;
	while (*splited_line)
	{
		if (ft_strlen(*splited_line) > 1 &&
			(*splited_line)[1] == 'x')
			color = ft_atoi_base((*splited_line) + 2, 16);
		else
		{
			num = ft_atoi(*splited_line);
			add_vortex(v, set_vortex(x, entry, num, color));
			color = WHITE;
			x++;
		}
		ft_strdel(&(*splited_line));
		splited_line++;
	}
	if (check_x != x && check_x != 0)
		terminate(NULL, "exception -> invalid data in map");
	check_x = x;
}

t_vortex3d		*make_vortex(char *line)
{
	char		**splited_line;
	static int	entry = 0;
	t_vortex3d	*v;

	v = NULL;
	if (line)
	{
		splited_line = ft_splinter(line, " ,\0");
		split_lines(splited_line, &v, entry);
		entry++;
		free(splited_line);
		splited_line = NULL;
	}
	return (v);
}

void			make_vertical_pointer(t_vortex_group *v_g)
{
	t_vortex_group	*v_g_temp;
	t_vortex3d		*v;
	t_vortex3d		*v_n;

	if (v_g == NULL)
		return ;
	v_g_temp = v_g;
	while (v_g_temp->next)
	{
		v = v_g_temp->vortex;
		v_n = v_g_temp->next->vortex;
		while (v)
		{
			v->next_v = v_n;
			v = v->next;
			v_n = v_n->next;
		}
		v_g_temp = v_g_temp->next;
	}
}

t_vortex_group	*read_file(char *file)
{
	t_vortex_group *v_g;

	v_g = (t_vortex_group *)for_each_gnl(file, (void *)make_vortex_group);
	if (!v_g)
		terminate(NULL, "exception -> invalid map");
	make_vertical_pointer(v_g);
	return (v_g);
}
