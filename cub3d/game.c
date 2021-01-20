/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:30:21 by gim               #+#    #+#             */
/*   Updated: 2021/01/20 16:31:05 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int			exit_game(/*t_game *game,*/int code)
{
	// clear_config(&game->config);
	// clear_window(&game->window);
	// clear_textures(game);
	// clear_sprites(&game->sprites);
	exit(code);
	return (code);
}