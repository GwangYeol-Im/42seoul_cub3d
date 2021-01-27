/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:54:10 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2021/01/27 14:33:49 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "mlx/mlx.h"
# include "config/config.h"
# include "engine/engine.h"
# include <stdio.h>

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_FORWARD 	126
# define KEY_BACKWARD	125

# define KEY_ESC	53

void			init_game(t_game *game, int save_opt);
int				finish_init(t_game *game);
int				exit_error(char *str);

int				exit_hook(t_game *game);
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				main_loop(t_game *game);

#endif
