/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:25:01 by gim               #+#    #+#             */
/*   Updated: 2021/01/20 17:17:12 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int			parse_line(t_config *config, char *line, t_list **map_buffer)
{
// line 검사
}

int			parse_config(t_config *config, char *file_path)
{
	int		fd;
	char	*line;
	int		re;
	t_list	*map_buffer;

	if (!ft_endwith(file_path, ".cub"))
		return (0);
	if ((fd = open(file_path, O_RDONLY)) < 0)
		return (0);
	map_buffer = NULL;
	while (get_next_line(fd, &line))
	{
		re = (re && parse_line(config, line, &map_buffer));
		free(line);
	}
	if (re && ft_strlen(line) > 0)
		// add something..
	free(line);
	close(fd);
	ft_lstclear(&map_buffer);
	return (re && parse_map(config, map_buffer));
}