/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:56:47 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 09:56:47 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr( const char *string, int searchedChar)
{
	int	i;

	i = ft_strlen(string);
	while (i > 0)
	{
		if (string[i] == (char)searchedChar)
			return ((char *)string + i);
		i--;
	}
	if (string[i] == (char)searchedChar)
		return ((char *)string - i);
	return (NULL);
}
