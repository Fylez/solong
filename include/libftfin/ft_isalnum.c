/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:52:36 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 09:52:36 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalnum(int character)
{
	if ((character < 'a' || character > 'z')
		&& (character < 'A' || character > 'Z'))
	{
		if (character < '0' || character > '9')
		{
			return (0);
		}
	}
	return (1);
}
/*
int main(void)
{
    printf("%d", ft_isalnum("br as"));
    return(0);
}*/