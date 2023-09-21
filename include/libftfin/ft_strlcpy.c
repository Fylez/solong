/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:56:03 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 10:40:38 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size -1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}	
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
int	main(void)
{
	char	dest[10] = "test";
	char	src[] = "012345678901234567890123456789";
	ft_strlcpy (dest, src, 10);
	write(1, &dest, 15);
}
*/
