/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:45:16 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2021/01/26 17:45:41 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int			ft_endwith(char *str, char *end)
{
	int		len;
	int		end_len;

	len = ft_strlen(str);
	end_len = ft_strlen(end);
	if (end_len > len)
		return (0);
	return (!ft_strcmp(str + len - end_len, end));
}
