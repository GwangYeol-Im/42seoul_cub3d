/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:55:51 by gim               #+#    #+#             */
/*   Updated: 2020/10/03 13:02:26 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_units(char const *s, char c)
{
	int		len;
	int		idx;

	len = 0;
	idx = 0;
	while (s[idx])
	{
		while (s[idx] == c && s[idx])
			idx++;
		if (!s[idx])
			return (len);
		len++;
		while (s[idx] != c && s[idx])
			idx++;
	}
	return (len);
}

char		*get_unit(char const *s, int srt, int end)
{
	char	*unit;
	int		idx;

	if (!(unit = malloc(sizeof(char) * (end - srt + 1))))
		return (0);
	idx = 0;
	while (srt < end)
		unit[idx++] = s[srt++];
	unit[idx] = 0;
	return (unit);
}

char		**ft_split(char const *s, char c)
{
	int		len;
	int		idx;
	int		foot_print;
	int		split_i;
	char	**split;

	len = count_units(s, c);
	if (!(split = malloc(sizeof(char *) * (len + 1))))
		return (0);
	split[len] = 0;
	split_i = 0;
	idx = 0;
	while (s[idx])
	{
		while (s[idx] == c && s[idx])
			idx++;
		if (!s[idx])
			return (split);
		foot_print = idx;
		while (s[idx] != c && s[idx])
			idx++;
		split[split_i++] = get_unit(s, foot_print, idx);
	}
	return (split);
}
