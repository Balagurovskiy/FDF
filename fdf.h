/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:01:50 by obalagur          #+#    #+#             */
/*   Updated: 2018/04/07 13:01:55 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <mlx.h>
# include <math.h>

# define BORDER 50
# define STEP 30
# define SCALE (STEP * frame->scale_mult)
# define DELTA_X (frame->width / 2 - (((frame->size_x - 1) / 2) * SCALE))
# define DELTA_Y (frame->height / 2 - (((frame->size_y - 1) / 2) * SCALE))

# define PI 3.14159265359
# define COS(a) (cos(PI / 180 * a))
# define SIN(a) (sin(PI / 180 * a))
# define DIST(x0, x1, y0, y1) sqrt(pow((x1 - x0), 2.0) + pow((y1 - y0), 2.0))
# define CENTER(x0, x1) ((x1 + x0) / 2)

# define ESC 53

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define ZOOM_IN 69
# define ZOOM_OUT 78

# define TOP_7 89
# define SIDE_8 91
# define FACE_9 92
# define ISO_0 82

# define ROT_X_4 86
# define ROT_X_1 83

# define ROT_Y_5 87
# define ROT_Y_2 84

# define ROT_Z_6 88
# define ROT_Z_3 85

# define COLOR_R 71
# define COLOR_G 75
# define COLOR_B 67

typedef enum	e_r_colors
{
	coral = 0xff7f50,
	lightcoral = 0xf08080,
	tomato = 0xff6347,
	orangered = 0xff4500,
	red = 0xff0000,
	hotpink = 0xff69b4,
	deeppink = 0xff1493,
	pink = 0xffc0cb

}				t_r_colors;
typedef enum	e_g_colors
{
	darkgreen = 0x6400,
	darkseagreen = 0x8fbc8f,
	seagreen = 0x2e8b57,
	lightseagreen = 0x20b2aa,
	palegreen = 0x98fb98,
	springgreen = 0xff7f,
	lawngreen = 0x7cfc00,
	green = 0xff00
}				t_g_colors;

typedef enum	e_b_colors
{
	blue = 0xff,
	deep_sky = 0xbfff,
	skyblue = 0x87ceeb,
	steelblue = 0x4682b4,
	lightblue = 0xadd8e6,
	powderblue = 0xb0e0e6,
	turquoise = 0x40e0d0,
	cyan = 0xffff
}				t_b_colors;

# define WHITE 0xFFFFFF
# define RED 0xAA0000
# define PURPLE 0xBB55AA
# define YELLOW 0xFFC832
# define GREEN 0x00AA00
# define BLUE 0x0055AA

typedef struct	s_vortex3d
{
	float				x0;
	float				y0;
	float				z0;
	float				x;
	float				y;
	float				z;
	int					color;
	struct s_vortex3d	*next;
	struct s_vortex3d	*next_v;
}				t_vortex3d;

typedef struct	s_vortex_group
{
	t_vortex3d				*vortex;
	size_t					size;
	struct s_vortex_group	*next;
}				t_vortex_group;

typedef struct	s_line
{
	float	dx;
	float	sx;
	float	dy;
	float	sy;
	float	err;
	float	x0;
	float	x1;
	float	y0;
	float	y1;
	float	dist;
}				t_line;

typedef struct	s_actions
{
	void				(*fun)();
	int					key;
	char				flag;
	float				step;
	struct s_actions	*next;
}				t_actions;

typedef struct	s_frame
{
	t_vortex_group			*v_group;
	t_actions				*actions;
	t_vortex3d				*center;
	char					rgb;
	size_t					size_x;
	size_t					size_y;
	size_t					width;
	size_t					height;
	void					*mlx;
	void					*win;
	float					scale_mult;

}				t_frame;

void			terminate(t_frame *frame, char *msg);
void			size_validator(t_frame *frame);
void			render_window(t_frame *fdf_frame);
int				deal_key(int key, t_frame *frame);
t_vortex3d		*get_end(t_frame *frame);
t_vortex3d		*find_center(t_frame *frame);
int				get_red_template(t_frame *frame, int z);
int				get_green_template(t_frame *frame, int z);
int				get_blue_template(t_frame *frame, int z);
int				get_color_id(t_frame *frame, int z);
void			colorize_by_z(t_frame *frame, char ort, float step);
t_vortex3d		*make_vortex(char *line);
t_vortex_group	*make_vortex_group(char *line);
void			make_vertical_pointer(t_vortex_group *v_g);
void			split_lines(char **splited_line, t_vortex3d **v, int entry);
t_vortex_group	*read_file(char *file);
t_vortex3d		*set_vortex(int x, int y, int z, int color);
void			add_vortex(t_vortex3d **first_node, t_vortex3d *new_node);
void			del_vortex(t_vortex3d **alst);
int				v_size(t_vortex3d *first_node);
t_vortex_group	*set_group(t_vortex3d	*vortex3d);
void			add_group(t_vortex_group **first_node,
							t_vortex_group *new_node);
void			del_group(t_vortex_group **alst);
int				v_g_size(t_vortex_group *first_node);
int				colorize(t_line	*l, t_vortex3d *v0, t_vortex3d *v1);
t_line			*set_line(t_vortex3d *v0, t_vortex3d *v1);
void			draw_line(t_frame *fdf_frame, t_vortex3d *v0, t_vortex3d *v1);
void			draw_grid(t_frame *fdf_frame);
void			rotate_matrix(t_vortex3d *v, float s, char ort);
void			rotate(t_frame *frame, char ort, float step);
void			rescale(t_frame *frame, t_vortex3d *v, float save);
void			set_scale(t_frame *fdf_frame);
void			change_scale(t_frame *frame, char flag, float step);
void			move(t_frame *frame, char direction, float step);
void			move_to_start(t_frame *frame);
t_actions		*action_container();
t_actions		*find_action(int key, t_actions *actions);
void			action_listener(int key, t_frame *frame);
t_actions		*new_action(void (*f)(t_frame *, char, float),
							int key, char flag, float step);
void			add_action(t_actions **first_node, t_actions *new_node);
void			del_action(t_actions **alst);
void			set_view(t_frame *frame, char flag, float step);
void			draw_menu(t_frame *frame);
void			fit_scale(t_frame *frame);

#endif
