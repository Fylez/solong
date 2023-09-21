/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:54:14 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 09:54:14 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalpha(int character)
{
	if ((character < 'a' || character > 'z')
		&& (character < 'A' || character > 'Z'))
		return (0);
	return (1);
}
/*
int main(void)
{
    printf("%d", ft_isalpha("br as"));
    return(0);
}
*/