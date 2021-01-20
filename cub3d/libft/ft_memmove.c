/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 13:22:44 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2020/10/03 14:21:55 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_src;
	unsigned char	temp[len];
	size_t			idx;

	if (!dst && !src)
		return (0);
	idx = 0;
	new_src = (unsigned char *)src;
	while (idx < len)
	{
		temp[idx++] = *new_src++;
	}
	ft_memcpy(dst, temp, len);
	return (dst);
}
