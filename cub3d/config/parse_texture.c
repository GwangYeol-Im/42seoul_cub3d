/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:22:59 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2021/01/27 10:13:42 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static char	*path_from_line(char *line)
{
	char	**strs;
	char	*path;

	if (!(strs = ft_split(line, ' ')) || strs_length(strs) != 2
		|| !ft_endwith(strs[1], ".xpm"))
	{
		strs_clear(strs);
		return (NULL);
	}
	path = ft_strdup(strs[1]);
	strs_clear(strs);
	return (path);
}

static int	texture_index(int key)
{
	if (key == C_NO)
		return (TEX_NORTH);
	else if (key == C_SO)
		return (TEX_SOUTH);
	else if (key == C_WE)
		return (TEX_WEST);
	else if (key == C_EA)
		return (TEX_EAST);
	else if (key == C_C)
		return (TEX_CEILING);
	else if (key == C_F)
		return (TEX_FLOOR);
	return (TEX_SPRITE);
}

int			parse_texture(t_config *config, int key, char *line)
{
	char	*path;
	int		idx;

	idx = texture_index(key);
	if (config->tex_path[idx])
	{
		free(config->tex_path[idx]);
		config->tex_path[idx] = NULL;
	}
	if (!(path = path_from_line(line)))
		return (0);
	config->tex_path[idx] = path;
	config->save_arg++;
	return (1);
}
