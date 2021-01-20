/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imgwang-yeol <imgwang-yeol@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:43:14 by gim               #+#    #+#             */
/*   Updated: 2021/01/20 12:55:17 by imgwang-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char *s1, char *s2, int n)
{
	int		len;
	int		i;
	int		j;
	char	*join;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	if (n == 1 || n == 3)
		free(s1);
	else if (n == 2 || n == 3)
		free(s2);
	return (join);
}
