/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:51:53 by lzaengel          #+#    #+#             */
/*   Updated: 2023/05/08 10:02:23 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi( const char *theString )
{
	long int		i;
	long int		result;
	int				neg;

	i = 0;
	neg = 1;
	result = 0;
	while (theString[i] == ' ' || theString[i] == '\t' || theString[i] == '\n'
		|| theString[i] == '\v' || theString[i] == '\f' || theString[i] == '\r')
		i++;
	if (theString[i] == '-')
	{
		neg = neg * -1;
		i++;
	}
	else if (theString[i] == '+')
		i++;
	while (theString[i] && ft_isdigit(theString[i]))
	{
		result = result * 10 + theString[i] - '0';
		i++;
	}
	return (result * neg);
}
