/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:29:50 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2021/01/26 17:46:50 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int				parse_dimensions(t_config *config, char *line)
{
	int			i;
	int			temp;
	char		**strs;

	i = 0;
	while (line[++i])
		if (line[i] != ' ' && !ft_isdigit(line[i]))
			return (0);
	if (!(strs = ft_split(line, ' ')) || strs_length(strs) != 3)
		return (strs_clear(strs));
	if ((temp = ft_atoi(strs[1])) <= 1)
		return (strs_clear(strs));
	config->requested_width = temp;
	if ((temp = ft_atoi(strs[2])) <= 1)
		return (strs_clear(strs));
	config->requested_height = temp;
	strs_clear(strs);
	return (1);
}

static int		str_to_color(char **strs)
{
	int			i;
	int			color;
	int			temp;

	i = -1;
	color = 0;
	while (strs[++i])
	{
		temp = ft_atoi(strs[i]);
		if (!(temp >= 0 && temp <= 255))
			return (-1);
		color = color | (temp << (16 - (i * 8)));
	}
	return (color);
}

int				parse_color(t_config *config, int key, char *line)
{
	int			i;
	unsigned	color;
	char		**strs;
	char		**strs2;

	i = 0;
	while (line[++i])
		if (!ft_in_set(line[i], " ,0123456789"))
			return (0);
	if (!(strs = ft_split(line, ' ')) || strs_length(strs) != 2 \
			|| !(strs2 = ft_split(strs[1], ','))
			|| strs_length(strs2) != 3)
		return (strs_clear(strs) || strs_clear(strs2));
	if ((int)((color = str_to_color(strs2))) < 0)
		return (strs_clear(strs) || strs_clear(strs2));
	config->color[(key == C_F) ? TEX_FLOOR : TEX_CEILING] = color;
	return ((strs_clear(strs) || strs_clear(strs2)) | 1);
}
