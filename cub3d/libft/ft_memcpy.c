/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:31:55 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2020/10/02 18:53:24 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_temp;

	if (!dst && !src)
		return (0);
	dst_temp = dst;
	while (n--)
	{
		*dst_temp++ = *(unsigned char *)src++;
	}
	return (dst);
}
