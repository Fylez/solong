/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <liamzaengel@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:12:54 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/17 21:12:54 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putstr(char *s, unsigned int *bwr)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", bwr);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], bwr);
		i++;
	}
}
