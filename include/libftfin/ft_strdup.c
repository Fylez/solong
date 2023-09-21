/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:55:37 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 10:17:41 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup( const char *source )
{
	char	*strd;
	int		i;

	i = 0;
	strd = (char *)malloc(sizeof(char) * (ft_strlen(source) + 1));
	if (!strd)
		return (NULL);
	while (source[i])
	{
		strd[i] = source[i];
		i++;
	}
	strd[i] = '\0';
	return (strd);
}
