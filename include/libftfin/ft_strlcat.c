/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:56:11 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/15 10:39:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	oglength;
	size_t	srclen;

	if (dst == 0 || src == 0)
		return (0);
	oglength = ft_strlen(dst);
	srclen = ft_strlen(src);
	j = 0;
	if (size <= oglength)
		return (size + srclen);
	j = 0;
	while (src[j] && (oglength + j < size - 1))
	{
		dst[oglength + j] = src[j];
		j++;
	}
	dst[oglength + j] = '\0';
	return (oglength + srclen);
}
/*
int	main(void)
{
	char	test1[100] = "Bonjour";
	char	test2[100] = "BzQnJOur";
	printf("%d", ft_strlcat(test1, test2, 14));
	printf("%s", test1);
}*/
