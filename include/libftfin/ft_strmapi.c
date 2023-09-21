/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:56:27 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 09:56:27 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rtab;
	unsigned int	i;

	rtab = ft_strdup(s);
	if (!rtab)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rtab[i] = (*f)(i, s[i]);
		i++;
	}
	return (rtab);
}
