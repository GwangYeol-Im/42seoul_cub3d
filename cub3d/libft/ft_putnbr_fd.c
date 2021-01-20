/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:56:04 by gim               #+#    #+#             */
/*   Updated: 2020/09/30 18:05:23 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		print_nbr(int n, int fd, int symbol)
{
	char	c;

	if (n == 0)
		return ;
	c = (n % 10 * symbol) + '0';
	print_nbr(n / 10, fd, symbol);
	ft_putchar_fd(c, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	int		symbol;

	symbol = n < 0 ? -1 : 1;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (symbol < 0)
		ft_putchar_fd('-', fd);
	print_nbr(n, fd, symbol);
}
