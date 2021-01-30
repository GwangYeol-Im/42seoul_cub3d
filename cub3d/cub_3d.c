/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:11:35 by gim               #+#    #+#             */
/*   Updated: 2021/01/31 00:05:40 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int			exit_hook(t_game *game)
{
	return (exit_game(game, EXIT_SUCCESS));
}

int		key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game, EXIT_SUCCESS);
	if (keycode == KEY_W || keycode == KEY_FORWARD)
		game->move.x = 1;
	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
		game->move.y = 1;
	else if (keycode == KEY_A)
		game->x_move.x = 1;
	else if (keycode == KEY_D)
		game->x_move.y = 1;
	return (0);
}

int		key_release(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game, EXIT_SUCCESS);
	if (keycode == KEY_W || keycode == KEY_FORWARD)
		game->move.x = 0;
	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
		game->move.y = 0;
	else if (keycode == KEY_A)
		game->x_move.x = 0;
	else if (keycode == KEY_D)
		game->x_move.y = 0;
	return (0);
}

int		main_loop(t_game *game)
{
	return (0);
}
