/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:51:14 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 09:51:14 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset( void *pointer, int value, size_t count )
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((char *)pointer)[i] = value;
		i++;
	}
	return (pointer);
}
/*
int main(void)
{
    char str[] = "bruh bruh bruhasdasas";
    ft_memset(str, 'a', 8);
    printf("%s",str );
    return(0);
}*/