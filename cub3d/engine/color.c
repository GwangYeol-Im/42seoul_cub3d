/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:22:29 by gim               #+#    #+#             */
/*   Updated: 2021/01/27 13:23:44 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int		get_tex_color(t_tex *tex, t_pos *pos)
{
	if (pos->x >= 0 && pos->x < tex->width
		&& pos->y >= 0 && pos->y < tex->height)
	{
		return (*(int*)(tex->ptr
			+ (4 * tex->width * (int)pos->y)
			+ (4 * (int)pos->x)));
	}
	return (0x0);
}
