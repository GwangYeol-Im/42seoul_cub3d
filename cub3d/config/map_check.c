/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:54:08 by gim               #+#    #+#             */
/*   Updated: 2021/01/27 11:33:27 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int			is_safe(int x, int y, t_config *config)
{
	int		min;

	min = x <= y ? x : y;
	return (min >= 0 && x < config->rows && y < config->cols);
}

void		search(int x, int y, t_config *config)
{
	config->search.visit[x][y] = '1';
	if (config->map[x][y] == ' ')
	{
		config->search.valid = 0;
		return ;
	}
	if (config->map[x][y] == '1' && !ft_in_set(config->map[x][y], DIRECTIONS))
		return ;
	if (is_safe(x - 1, y, config) && config->search.visit[x - 1][y] == '0')
		search(x - 1, y, config);
	if (is_safe(x + 1, y, config) && config->search.visit[x + 1][y] == '0')
		search(x + 1, y, config);
	if (is_safe(x, y - 1, config) && config->search.visit[x][y - 1] == '0')
		search(x, y - 1, config);
	if (is_safe(x, y + 1, config) && config->search.visit[x][y + 1] == '0')
		search(x, y + 1, config);
	return ;
}

char		*check_valid_str(t_config *config, char *content, int x)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(char) * (config->cols + 1))))
		return (0);
	str[config->cols] = '\0';
	i = -1;
	while (content[++i])
	{
		if (!ft_in_set(content[i], VALID_MAP_CHARACTERS))
		{
			free(str);
			return (0);
		}
		if (ft_in_set(content[i], DIRECTIONS))
		{
			config->camera++;
			config->player.x = x;
			config->player.y = i;
		}
		str[i] = content[i];
	}
	while (i < config->cols)
		str[i++] = ' ';
	return (str);
}

int			check_valid_map(t_config *config)
{
	int		i;

	if (!(config->search.visit = malloc(sizeof(char *) * (config->rows + 1))))
		return (0);
	i = -1;
	while (++i < config->rows)
	{
		if (!(config->search.visit[i] = malloc(sizeof(char) * (config->cols + 1))))
			return (0);
		ft_memset(config->search.visit[i], '0', config->cols);
	}
	config->search.valid = 1;
	search((int)config->player.x, (int)config->player.y, config);
	if (!config->search.valid)
		return (strs_clear(config->search.visit));
	strs_clear(config->search.visit);
	return (1);
}
