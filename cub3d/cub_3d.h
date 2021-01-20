/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:11:17 by gim               #+#    #+#             */
/*   Updated: 2021/01/20 16:31:23 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "config/config.h"
# include "mlx/mlx.h"

typedef struct	s_game
{
	t_config	config;
}				t_game;

int				exit_game(/*t_game *game,*/int code);

#endif