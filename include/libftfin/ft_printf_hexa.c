/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <liamzaengel@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:12:29 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/17 21:14:19 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_printhexa(unsigned int n, unsigned int *bwr)
{
	char	*base;
	char	c;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_printhexa(n / 16, bwr);
	c = base[n % 16];
	ft_putchar(c, bwr);
}

void	ft_printhexacaps(unsigned int n, unsigned int *bwr)
{
	char	*base;
	char	c;

	base = "0123456789ABCDEF";
	if (n >= 16)
		ft_printhexacaps(n / 16, bwr);
	c = base[n % 16];
	ft_putchar(c, bwr);
}

void	ft_printptr(unsigned long long n, unsigned int *bwr)
{
	char	*base;
	char	c;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_printptr(n / 16, bwr);
	c = base[n % 16];
	ft_putchar(c, bwr);
}

void	ft_ptr(unsigned long long n, unsigned int *bwr)
{
	if (n == 0)
	{
		ft_putstr("(nil)", bwr);
		return ;
	}
	else
	{
		ft_putstr("0x", bwr);
		ft_printptr(n, bwr);
	}
	return ;
}
