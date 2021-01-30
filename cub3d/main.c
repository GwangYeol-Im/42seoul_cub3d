/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:51:37 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2021/01/30 17:11:58 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int			exit_error(t_game *game, char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	exit_game(game, EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int			main(int argc, char **argv)
{
	t_game	game;
	int		save_opt;

	save_opt = 0;
	if (!(argc == 2 || argc == 3))
		return (exit_error(&game, "\nError: Invalid arguments count.\n"));
	if (argc == 3 && !(save_opt = !ft_strcmp(argv[2], "--save")))
		return (exit_error(&game, "\nError: Invalid option.\n"));
	init_game(&game, save_opt);
	if (!parse_config(&game.config, argv[1]))
		return (exit_error(&game, "\nError: Invalid map.\n"));
	if (!finish_init(&game))
		return (EXIT_FAILURE);
	printf("%f %f\n", game.camera.dir.x, game.camera.dir.y);
	mlx_hook(game.window.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.window.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	mlx_hook(game.window.win, X_EVENT_EXIT, 0, &exit_hook, &game);
	mlx_loop_hook(game.window.ptr, &main_loop, &game);
	mlx_loop(game.window.ptr);
	return (EXIT_SUCCESS);
}
