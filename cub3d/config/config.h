/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:18:05 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2021/01/20 17:15:59 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <fcntl.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"

# define DIRECTIONS "NSEW"
# define VALID_MAP_CHARACTERS " 01234NSEW"

# define C_R				0
# define C_NO				1
# define C_SO				2
# define C_WE				3
# define C_EA				4
# define C_S				5
# define C_SU				6
# define C_SC				7
# define C_FT				8
# define C_ST				9
# define C_F				10
# define C_C				11
# define C_MAP				12
# define C_LAST				13

# define TEXTURES			9
# define TEX_NORTH			0
# define TEX_SOUTH			1
# define TEX_WEST			2
# define TEX_EAST			3
# define TEX_SKY			4
# define TEX_FLOOR			5
# define TEX_SPRITE			6
# define TEX_SPRITE_UP		7
# define TEX_SPRITE_C		8

typedef struct	s_config
{
	int			requested_width;
	int			requested_height;
	int			*map;
	int			rows;
	int			colums;
	int			save_arg;
	double		rotate_speed;
	double		move_speed;
	char		*tex_path[TEXTURES];
	unsigned	color[TEXTURES];
	int			set[C_LAST];
	double		fov;
}				t_config;

int			parse_config(t_config *config, char *file_path);

#endif