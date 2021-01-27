/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:15:47 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2021/01/27 15:30:31 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

void		init_game(t_game *game, int save_opt)
{
	int		i;

	init_config(&game->config);
	set_pos(&game->move, 0, 0);
	set_pos(&game->x_move, 0, 0);
	set_pos(&game->rotate, 0, 0);
	game->option = save_opt;
	game->sprites = NULL;
	i = 0;
	while (i < TEXTURES)
		game->tex[i++].tex = NULL;
}

int			finish_init(t_game *game)
{
	if (!init_window(&game->window, &game->config))
		return (exit_error("Error:\nmlx failed to create window or image.\n"));
	find_start_pos(&game->config, &game->camera);
	find_start_angle(&game->config, &game->camera);
	// if (!load_textures(game))
	// 	return (exit_error("Error:\nfailed to load texture(s).\n"));
	return (1);
}