/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:41:40 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 20:21:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_nbl(int n)
{
	long	nb;
	int		i;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		i++;
		nb = nb * -1;
	}	
	if (nb >= 10)
		i = i + (ft_nbl(nb / 10));
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	long	nb;
	int		i;
	int		j;

	nb = n;
	i = ft_nbl(nb);
	j = i - 1;
	nbr = malloc(sizeof(char) * (i + 1));
	if (!nbr)
		return (NULL);
	if (nb < 0)
	{
		nbr[0] = '-';
		nb = nb * -1;
	}
	if (nb == 0)
		nbr[0] = '0';
	while (nb > 0)
	{
		nbr[j] = (nb % 10) + '0';
		nb = (j--, nb / 10);
	}
	nbr[i] = '\0';
	return (nbr);
}
/*int	main()
{
	char *res = ft_itoa(2147483647);
}*/