/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:51:47 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 10:20:37 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr( const void *memoryBlock, int searchedChar, size_t size )
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((unsigned char *) memoryBlock)[i] == (unsigned char)searchedChar)
		{
			return (((unsigned char *) memoryBlock) + i);
		}
		i++;
	}
	return (NULL);
}
