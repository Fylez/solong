/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:55:41 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 09:55:41 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	sf = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sf)
		return (NULL);
	while (s1[i])
	{
		sf[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		sf[j] = s2[i];
		i++;
		j++;
	}
	sf[j] = '\0';
	return (sf);
}
