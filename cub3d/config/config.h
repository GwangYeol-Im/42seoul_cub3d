/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:19:11 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2021/01/30 16:45:42 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

# define DIRECTIONS "NSEW"
# define VALID_MAP_CHARACTERS " 01234NSEW"

# define C_R				0
# define C_NO				1
# define C_SO				2
# define C_WE				3
# define C_EA				4
# define C_S				5
# define C_F				6
# define C_C				7
# define C_MAP				8
# define C_LAST				9

# define TEXTURES			7
# define TEX_NORTH			0
# define TEX_SOUTH			1
# define TEX_WEST			2
# define TEX_EAST			3
# define TEX_CEILING		4
# define TEX_FLOOR			5
# define TEX_SPRITE			6

# define DX 
# define DY {0, 0, -1, 1}

typedef struct	s_search
{
	char		**visit;
	int			valid;
}				t_search;

typedef struct	s_config
{
	int			requested_width;
	int			requested_height;
	char		**map;
	int			rows;
	int			cols;
	int			save_arg;
	double		rotate_speed;
	double		move_speed;
	char		*tex_path[TEXTURES];
	unsigned	color[TEXTURES];
	int			set[C_LAST];
	double		fov;
	int			camera;
	t_pos		player;
	t_search	search;
}				t_config;

void			init_config(t_config *config);
int				parse_config(t_config *config, char *file_path);
int				ft_endwith(char *str, char *end);
int				parse_dimensions(t_config *config, char *line);
int				parse_color(t_config *config, int key, char *line);
int				parse_texture(t_config *config, int key, char *line);
int				parse_map(t_config *config, t_list *map_buffer);
int				check_valid_map(t_config *config);
char			*check_valid_str(t_config *config, char *content, int x);
int				clear_config(t_config *config);

#endif
