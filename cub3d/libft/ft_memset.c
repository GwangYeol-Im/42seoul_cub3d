/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:54:55 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2020/09/29 13:47:04 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*temp;

	temp = ptr;
	while (num--)
	{
		*temp++ = (unsigned char)value;
	}
	return (ptr);
}
