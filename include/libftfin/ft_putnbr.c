/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <liamzaengel@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:12:47 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/17 21:12:47 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putnbr(int n, unsigned int *bwr)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-', bwr);
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, bwr);
	c = nb % 10 + '0';
	ft_putchar(c, bwr);
}

void	ft_putunbr(unsigned int n, unsigned int *bwr)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10, bwr);
	c = n % 10 + '0';
	ft_putchar(c, bwr);
}
