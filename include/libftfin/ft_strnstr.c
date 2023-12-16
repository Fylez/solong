/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:56:41 by lzaengel          #+#    #+#             */
/*   Updated: 2023/12/16 16:20:38 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str || !tofind)
		return (0);
	if (tofind[j] == '\0')
		return ((char *)str);
	while (str[i] && i < n)
	{
		while (str[i + j] == tofind[j] && i + j < n)
		{
			j++;
			if (tofind[j] == '\0' && str[i + j] == '\0')
				return (&((char *)str)[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
