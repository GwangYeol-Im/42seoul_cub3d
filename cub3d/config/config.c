/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:23:01 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2021/01/30 16:45:33 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int				clear_config(t_config *config)
{
	int	i;

	i = 0;
	while (i < TEXTURES)
	{
		if (config->tex_path[i])
			free(config->tex_path[i]);
		config->tex_path[i] = NULL;
		i++;
	}
	if (config->map)
		strs_clear(config->map);
	config->map = NULL;
	return (0);
}

void			init_config(t_config *config)
{
	int	i;

	config->requested_width = 800;
	config->requested_height = 400;
	i = 0;
	while (i < TEXTURES)
		config->tex_path[i++] = NULL;
	config->color[TEX_NORTH] = 0xFFFFFF;
	config->color[TEX_SOUTH] = 0xCCCCCC;
	config->color[TEX_WEST] = 0xFF44FF;
	config->color[TEX_EAST] = 0x44FF44;
	config->color[TEX_CEILING] = 0x33C6E3;
	config->color[TEX_FLOOR] = 0xA0764C;
	config->map = NULL;
	config->rows = 0;
	config->cols = 0;
	config->save_arg = 0;
	config->rotate_speed = 0.11;
	config->move_speed = 0.11;
	config->fov = 0.66;
	config->camera = 0;
	i = 0;
	while (i < C_LAST)
		config->set[i++] = 0;
}

static int		config_key(char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (C_R);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (C_NO);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (C_SO);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (C_WE);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (C_EA);
	else if (line[0] == 'S' && line[1] == ' ')
		return (C_S);
	else if (line[0] == 'F' && line[1] == ' ')
		return (C_F);
	else if (line[0] == 'C' && line[1] == ' ')
		return (C_C);
	return (C_MAP);
}

int				parse_line(t_config *config, char *line, t_list **map_buffer)
{
	static int	empty_in_map = 0;
	static int	content_after = 0;
	int			length;
	int			key;

	length = ft_strlen(line);
	if (length == 0 && config->set[C_MAP])
		empty_in_map = 1;
	if (empty_in_map && content_after)
		return (0);
	if (length == 0)
		return (1);
	key = config_key(line);
	if (key != C_MAP && (config->set[key] || config->set[C_MAP]))
		return (0);
	if (key == C_R)
		return (parse_dimensions(config, line));
	else if (key >= C_NO && key <= C_S)
		return (parse_texture(config, key, line));
	else if (key == C_F || key == C_C)
		return (parse_color(config, key, line));
	config->set[key] = 1;
	if (empty_in_map)
		content_after = 1;
	return (!!ft_lstadd_back(map_buffer, ft_strdup(line)));
}

int				parse_config(t_config *config, char *file_path)
{
	int			fd;
	char		*line;
	int			re;
	t_list		*map_buffer;

	if (!ft_endwith(file_path, ".cub"))
		return (0);
	if ((fd = open(file_path, O_RDONLY)) < 0)
		return (0);
	map_buffer = NULL;
	re = 1;
	while (get_next_line(fd, &line))
	{
		re = (re && parse_line(config, line, &map_buffer));
		free(line);
	}
	if (re && ft_strlen(line) > 0)
		re = !!ft_lstadd_back(&map_buffer, ft_strdup(line));
	free(line);
	close(fd);
	if (!re || config->save_arg != 8 || !parse_map(config, map_buffer))
		return (ft_lstclear(&map_buffer));
	ft_lstclear(&map_buffer);
	return (1);
}
