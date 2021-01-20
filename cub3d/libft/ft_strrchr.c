/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:45:21 by gim               #+#    #+#             */
/*   Updated: 2020/09/29 21:48:05 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*temp;

	len = ft_strlen(s);
	temp = (char *)s;
	while (len >= 0)
	{
		if (temp[len] == c)
			return (temp + len);
		len--;
	}
	return (0);
}
