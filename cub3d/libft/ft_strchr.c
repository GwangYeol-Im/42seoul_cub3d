/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:18:26 by gim               #+#    #+#             */
/*   Updated: 2020/09/29 18:43:38 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*temp;

	temp = (char *)s;
	while (*temp)
	{
		if (*temp == c)
			return (temp);
		temp++;
	}
	if (*temp == c)
		return (temp);
	return (NULL);
}
