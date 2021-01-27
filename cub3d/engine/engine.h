/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:50:36 by gim               #+#    #+#             */
/*   Updated: 2021/01/27 14:35:27 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <stdio.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../config/config.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_RELEASE	5
# define X_EVENT_MOUSE_MOVE		6
# define X_EVENT_EXIT			17

# define BEST_RATIO				1.7777777778

typedef struct	s_raysult
{
	int			column;
	int			row;
	double		distance;
	int			direction;
	int			side;
	int			height;
	t_pos		ray_pos;
	t_pos		ray_dir;
	t_pos		map_pos;
	t_pos		side_dist;
	t_pos		delta_dist;
	t_pos		step;
	double		wall_x;
	t_pos		floor_wall;
	t_pos		c_floor;
}				t_raysult;

typedef struct	s_image
{
	void		*img;
	void		*ptr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct	s_tex
{
	char	*path;
	void	*tex;
	void	*ptr;
	t_pos	start;
	t_pos	end;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}				t_tex;

typedef struct	s_sprite_draw
{
	int			sprite_screen;
	t_pos		pos;
	t_pos		transform;
	t_pos		spr_s;
	t_pos		draw_x;
	t_pos		draw_y;
	t_pos		tex_pos;
	int			fact;
	int			draw_y_org;
}				t_sprite_draw;

typedef struct	s_sprite
{
	t_pos			pos;
	double			distance;
	t_tex			*tex;
	struct s_sprite	*next;
	struct s_sprite	*sorted;
}				t_sprite;

typedef struct	s_window
{
	void		*ptr;
	void		*win;
	t_image		screen;
	t_pos		size;
	t_pos		half;
	double		ratio;
}				t_window;

typedef struct	s_camera
{
	t_pos		pos;
	t_pos		dir;
	t_pos		x_dir;
	t_pos		plane;
}				t_camera;

typedef struct	s_game
{
	t_config	config;
	t_window	window;
	t_camera	camera;
	t_sprite	*sprites;
	t_tex		tex[TEXTURES];
	t_pos		move;
	t_pos		x_move;
	t_pos		rotate;
	int			option;
	double		camera_x[1920];
	double		depth[1920];
	double		sf_dist[1080];
	double		cos[2];
	double		sin[2];
}				t_game;

int				init_window(t_window *window, t_config *config);
int				fint(double x);
int				check_top(t_pos pos);
int				check_bottom(t_pos pos, t_config config);
int				in_map(t_pos pos, t_config config);
int				map(t_pos pos, t_config config);
int				map_xy(double x, double y, t_config config);
void			find_start_pos(t_config *config, t_camera *camera);
void			find_start_angle(t_config *config, t_camera *camera);
int				load_textures(t_game *game);
int				get_tex_color(t_tex *tex, t_pos *pos);

# endif