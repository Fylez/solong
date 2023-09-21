/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <liamzaengel@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:12:39 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/17 21:12:39 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putchar(char c, unsigned int *bwr)
{
	write(1, &c, 1);
	*bwr = *bwr + 1;
}
/*
int main()
{
    ft_putchar_fd('c', 2);
}*/