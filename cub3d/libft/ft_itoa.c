/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:42:25 by gim               #+#    #+#             */
/*   Updated: 2020/10/01 11:35:24 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_int_len(int n)
{
	int		len;

	len = (n <= 0) ? 1 : 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		symbol;
	int		len;
	char	*str;

	symbol = (n < 0) ? -1 : 1;
	len = get_int_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = 0;
	if (symbol < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (--len >= 0 && n)
	{
		str[len] = (n % 10 * symbol) + '0';
		n /= 10;
	}
	return (str);
}
