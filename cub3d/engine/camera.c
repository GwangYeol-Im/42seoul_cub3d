/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:35:44 by gim               #+#    #+#             */
/*   Updated: 2021/01/27 15:11:03 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void			find_start_pos(t_config *config, t_camera *camera)
{
	camera->pos.x = config->player.y;
	camera->pos.y = config->player.x;
}

void			find_start_angle(t_config *config, t_camera *camera)
{
	if (map(camera->pos, *config) == 'N')
	{
		set_pos(&camera->dir, 0., -1.);
		set_pos(&camera->plane, config->fov, 0.);
	}
	else if (map(camera->pos, *config) == 'E')
	{
		set_pos(&camera->dir, 1., 0.);
		set_pos(&camera->plane, 0., config->fov);
	}
	else if (map(camera->pos, *config) == 'S')
	{
		set_pos(&camera->dir, 0., 1.);
		set_pos(&camera->plane, -config->fov, 0.);
	}
	else if (map(camera->pos, *config) == 'W')
	{
		set_pos(&camera->dir, -1., 0.);
		set_pos(&camera->plane, 0., -config->fov);
	}
	set_pos(&camera->x_dir, camera->dir.y, -camera->dir.x);
	config->map[fint(camera->pos.y)][fint(camera->pos.x)] = '0';
}
