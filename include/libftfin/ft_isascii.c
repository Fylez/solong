/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:54:28 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 09:54:28 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isascii(int character)
{
	if (character < 0 || character > 127)
	{
		return (0);
	}
	return (1);
}
/*
int main(void)
{
    printf("%d", ft_isascii("br as"));
    return(0);
}*/