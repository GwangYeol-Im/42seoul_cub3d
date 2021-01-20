/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:31:32 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2020/09/29 13:48:15 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	len;

	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	idx = 0;
	while (idx < dstsize - 1)
	{
		if (src[idx] == '\0')
		{
			dst[idx] = '\0';
			return (len);
		}
		dst[idx] = src[idx];
		idx++;
	}
	dst[dstsize - 1] = '\0';
	return (len);
}
