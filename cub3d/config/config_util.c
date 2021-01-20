/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:54:09 by gim               #+#    #+#             */
/*   Updated: 2021/01/20 16:58:25 by gim              ###   ########.fr       */
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
	return (!ft_strncmp(str + len - end_len, end, end_len));
}