/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:51:23 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 09:51:23 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove( void *destination, const void *source, size_t size )
{
	if (!destination || !source)
		return (0);
	if (destination < source)
		ft_memcpy((void *)destination, (void *)source, size);
	else
	{
		while (size > 0)
		{
			((char *)destination)[size - 1] = ((char *)source)[size - 1];
			size--;
		}
	}
	return (destination);
}
/*int main(void)
{	
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;
	dest = src + 1;
	ft_memmove(src, dest, 8);
	write(1, dest, 22);
} */