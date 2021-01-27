/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:38:27 by gim               #+#    #+#             */
/*   Updated: 2021/01/27 15:04:25 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int		fint(double x)
{
	return (int)floor(x);
}

int		check_top(t_pos pos)
{
	return (fint(pos.x) >= 0 && fint(pos.y) >= 0);
}

int		check_bottom(t_pos pos, t_config config)
{
	return (fint(pos.y) < config.rows && fint(pos.x) < config.cols);
}

int		in_map(t_pos pos, t_config config)
{
	return (check_top(pos) && check_bottom(pos, config));
}

int		map(t_pos pos, t_config config)
{
	return (config.map[fint(pos.y)][fint(pos.x)]);
}

int		map_xy(double x, double y, t_config config)
{
	return (config.map[fint(y)][fint(x)]);
}
