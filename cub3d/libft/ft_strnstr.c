/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:59:30 by gim               #+#    #+#             */
/*   Updated: 2020/10/02 20:34:19 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *find, size_t len)
{
	size_t	f_len;
	size_t	b_len;
	size_t	size;

	if (!*find)
		return ((char *)big);
	f_len = ft_strlen(find);
	b_len = ft_strlen(big);
	if (b_len < f_len || len < f_len)
		return (0);
	size = b_len > len ? len : b_len;
	while (size-- >= f_len)
	{
		if (ft_memcmp(big, find, f_len) == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
