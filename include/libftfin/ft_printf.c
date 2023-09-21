/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <liamzaengel@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:07:50 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/17 21:12:06 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_choose(char c, va_list args, unsigned int *bwr)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), bwr);
	if (c == 's')
		ft_putstr(va_arg(args, char *), bwr);
	if (c == 'p')
		ft_ptr(va_arg(args, unsigned long long), bwr);
	if (c == 'd')
		ft_putnbr(va_arg(args, int), bwr);
	if (c == 'u')
		ft_putunbr(va_arg(args, unsigned int), bwr);
	if (c == 'i')
		ft_putnbr(va_arg(args, int), bwr);
	if (c == 'x')
		ft_printhexa(va_arg(args, unsigned int), bwr);
	if (c == 'X')
		ft_printhexacaps(va_arg(args, unsigned int), bwr);
	if (c == '%')
		ft_putchar('%', bwr);
	return ;
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				i;
	unsigned int	b;
	unsigned int	*bwr;

	va_start(args, str);
	b = 0;
	bwr = &b;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_choose(str[i + 1], args, bwr);
			i++;
		}
		else
			ft_putchar(str[i], bwr);
		i++;
	}
	return (b);
}
/*
int	main()
{	
	printf("\nW\n %u %u ", ULONG_MAX, -ULONG_MAX);
	printf("\nW\n %d %d ", LONG_MIN, LONG_MAX);
	
	printf("\nA1\n %p %p ", 0, 0);
	printf("\nA2\n %p %p ", ULONG_MAX, -ULONG_MAX);
	printf("\nA3\n %p %p ", LONG_MIN, LONG_MAX);
	printf("\n\n\n\n\n\n\n");
	ft_printf("\nB1\n %p %p ", 0, 0);
	ft_printf("\nB2\n %p %p ", ULONG_MAX, -ULONG_MAX);
	ft_printf("\nB3\n %p %p ", LONG_MIN, LONG_MAX);
	return(0);
}*/