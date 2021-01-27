/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:11:35 by gim               #+#    #+#             */
/*   Updated: 2021/01/27 14:28:25 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

// int		exit_hook(t_game *game)
// {
// 	return (exit_game(game, EXIT_SUCCESS));
// }

// int		key_press(int keycode, t_game *game)
// {
// 	if (keycode == KEY_W || keycode == KEY_FORWARD)
// 		game->move.x = 1;
// 	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
// 		game->move.y = 1;
// 	if (keycode == KEY_A)
// 		game->x_move.x = 1;
// 	else if (keycode == KEY_D)
// 		game->x_move.y = 1;
// 	if (keycode == KEY_LEFT)
// 		game->rotate.x = 1;
// 	else if (keycode == KEY_RIGHT)
// 		game->rotate.y = 1;
// 	return (0);
// }

// int		key_release(int keycode, t_game *game)
// {
// 	if (keycode == KEY_W || keycode == KEY_FORWARD)
// 		game->move.x = 0;
// 	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
// 		game->move.y = 0;
// 	else if (keycode == KEY_A)
// 		game->x_move.x = 0;
// 	else if (keycode == KEY_D)
// 		game->x_move.y = 0;
// 	else if (keycode == KEY_LEFT)
// 		game->rotate.x = 0;
// 	else if (keycode == KEY_RIGHT)
// 		game->rotate.y = 0;
// 	else if (keycode == KEY_ESC)
// 		return (exit_game(game, EXIT_SUCCESS));
// 	return (0);
// }

// int		main_loop(t_game *game)
// {
// 	static int	update = 1;

// 	if (game->move.x || game->move.y)
// 		update = move_camera(game, (game->move.x) ? 0 : 1);
// 	if (game->x_move.x || game->x_move.y)
// 		update = move_perp_camera(game, (game->x_move.x) ? 0 : 1);
// 	if (game->rotate.x || game->rotate.y)
// 		update = rotate_camera(game, (game->rotate.x) ? 0 : 1);
// 	if (update)
// 	{
// 		update_screen(game);
// 		update_window(game);
// 	}
// 	update = 0;
// 	return (0);
// }
