/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:52:06 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 10:28:47 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc( size_t elementCount, size_t elementSize )
{
	void	*strd;

	if (elementSize > sizeof(char) * 2147483424
		|| elementCount > sizeof(char) * 2147483424)
		return (NULL);
	strd = malloc(elementSize * elementCount);
	if (!strd)
	{
		return (NULL);
	}
	ft_bzero(strd, (elementCount * elementSize));
	return (strd);
}
