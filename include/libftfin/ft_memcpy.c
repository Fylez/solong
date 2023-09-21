/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:51:39 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 09:51:39 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy( void *destination, const void *source, size_t size )
{
	size_t	i;

	if (!destination || !source)
		return (destination);
	i = 0;
	while (i < size)
	{
		((char *)destination)[i] = ((char *)source)[i];
		i++;
	}
	return (destination);
}
/*
int main(void)
{
    char str[] = "bruh bruh bruhasdasas";
	 char str2[] = "asdsadsasd bruhasdasas";
    ft_memcpy(str, str2, 8);
    printf("%s",str );
    return(0);
}
*/