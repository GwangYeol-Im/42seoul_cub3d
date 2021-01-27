/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:02:22 by gim               #+#    #+#             */
/*   Updated: 2021/01/27 14:57:03 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int			check_rows(char *line, int len)
{
	return (line[0] == ' ' || line[0] == '1' || line[len - 1] == '0' || line[len - 1] == '1');
}

int			check_left_right_borders(t_list *map_buffer, t_config *config)
{
	int		cols;

	while (map_buffer)
	{
		cols = ft_strlen(map_buffer->content);
		if (!check_rows(map_buffer->content, cols))
			return (0);
		config->cols = cols > config->cols ? cols : config->cols;
		map_buffer = map_buffer->next;
		config->rows++;
	}
	return (1);
}

int			check_columns(char *line)
{
	int		i;

	i = -1;
	while (line[++i])
		if (line[i] != '1' && line[i] != ' ')
			return (0);
	return (1);
}

int			check_top_bottom_borders(t_list *map_buffer)
{
	t_list	*last;

	if (!map_buffer)
		return (0);
	if (!check_columns(map_buffer->content))
		return (0);
	last = ft_lstlast(map_buffer);
	if (!check_columns(last->content))
		return (0);
	return (1);
}

int			parse_map(t_config *config, t_list *map_buffer)
{
	int		i;
	t_list	*temp;

	if (!check_top_bottom_borders(map_buffer) || !check_left_right_borders(map_buffer, config))
		return (0);
	if (!(config->map = malloc(sizeof(char *) * (config->rows + 1))))
		return (0);
	config->map[config->rows] = NULL;
	i = -1;
	temp = map_buffer;
	while (config->map[++i])
	{
		if (!(config->map[i] = check_valid_str(config, temp->content, i)))
			return (strs_clear(config->map));
		temp = temp->next;
	}
	if (config->camera != 1 || !check_valid_map(config))
		return (strs_clear(config->map));
	return (1);
}