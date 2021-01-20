/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:54:34 by gim               #+#    #+#             */
/*   Updated: 2020/10/01 00:45:38 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_int(char *str, int len)
{
	int		num;
	int		idx;

	num = 0;
	idx = 0;
	while (idx < len)
		num = num * 10 + (str[idx++] - '0');
	return (num);
}

int			ft_isspace(char c)
{
	if (c == '\t' || c == '\v' || c == '\n')
		return (1);
	if (c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		symbol;
	int		idx;
	char	*new_str;

	new_str = (char *)str;
	symbol = 1;
	while (ft_isspace(*new_str))
		new_str++;
	if (*new_str == '+' || *new_str == '-')
	{
		symbol = *new_str == '-' ? symbol * -1 : symbol;
		new_str++;
	}
	if (!ft_isdigit(*new_str))
		return (0);
	idx = 0;
	while (ft_isdigit(new_str[idx]))
		idx++;
	return (get_int(new_str, idx) * symbol);
}
