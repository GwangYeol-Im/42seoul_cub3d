/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:54:10 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2021/01/26 17:49:39 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "mlx/mlx.h"
# include "config/config.h"

typedef struct	s_game
{
	t_config	config;
	int			option;
}				t_game;

void			init_game(t_game *game, int save_opt);

#endif
