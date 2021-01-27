/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:51:37 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2021/01/27 10:50:28 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int			exit_error(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (EXIT_FAILURE);
}

int			main(int argc, char **argv)
{
	t_game	game;
	int		save_opt;

	save_opt = 0;
	if (!(argc == 2 || argc == 3))
		return (exit_error("\nError: Invalid arguments count.\n"));
	if (argc == 3 && !(save_opt = !ft_strcmp(argv[2], "--save")))
		return (exit_error("\nError: Invalid option.\n"));
	init_game(&game, save_opt);
	if (!parse_config(&game.config, argv[1]))
		return (exit_error("\nError: Invalid map.\n"));
	printf("hahaha!\n");
	return (0);
}
