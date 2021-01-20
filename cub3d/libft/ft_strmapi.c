/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:03:07 by gim               #+#    #+#             */
/*   Updated: 2020/09/30 14:35:29 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	int		len;
	int		idx;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	map = malloc(sizeof(char) * (len + 1));
	if (!map)
		return (0);
	map[len] = 0;
	idx = 0;
	while (s[idx])
	{
		map[idx] = f(idx, s[idx]);
		idx++;
	}
	return (map);
}
