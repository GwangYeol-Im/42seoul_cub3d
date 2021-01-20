/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:33:53 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2021/01/20 16:36:06 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3d.h"

int			exit_error(t_game *game, char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	// exit_game(game, EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int			main(int argc, char **argv)
{
	t_game	game;
	int		save_opt;

	if (!(argc >= 2 && argc <= 3))
		return (exit_error(&game, "\nError: Invalid arguments count.\n"));
	if (argc == 3)
		if ((save_opt = !ft_strncmp(argv[2], "--save", ft_strlen(argv[2]))))
			return (exit_error(&game, "\nError: Invalid option.\n"));
	if (!parse_config(&game.config, argv[1]))
		return (exit_error(&game, "\nError: Invalid map.\n"));
	return (EXIT_SUCCESS);
}
