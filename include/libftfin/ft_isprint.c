/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:55:19 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 09:55:19 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isprint(int character)
{
	if (character < 32 || character > 126)
	{
		return (0);
	}
	return (1);
}
/*
int main(void)
{
    printf("%d", ft_isprint("br as"));
    return(0);
}*/