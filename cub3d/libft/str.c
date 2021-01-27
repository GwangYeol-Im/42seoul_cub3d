/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:48:46 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2021/01/26 22:45:12 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_in_set(char c, char *set)
{
	int		i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

int			strs_length(char **strs)
{
	int		length;

	length = 0;
	while (strs[length])
		length++;
	return (length);
}

int			strs_clear(char **strs)
{
	int		i;

	if (strs == NULL)
		return (0);
	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
	return (0);
}
