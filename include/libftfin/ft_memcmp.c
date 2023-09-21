/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:47:59 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 10:25:28 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<string.h>
#include<stdio.h>

int	ft_memcmp( const void *pointer1, const void *pointer2, size_t size )
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((unsigned char *)pointer1)[i] != ((unsigned char *)pointer2)[i])
		{
			return (((unsigned char *)pointer1)[i]
				- ((unsigned char *)pointer2)[i]);
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	test1[] = "Bonjour";
	char	test2[] = "BonjoOur";
	printf("%d", ft_strncmp("test\200", "test\0", 6));
	printf("%d", strncmp("test\200", "test\0", 6));
}*/