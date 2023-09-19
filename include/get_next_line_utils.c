/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:26:10 by fylez             #+#    #+#             */
/*   Updated: 2023/07/26 15:54:54 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*check if there a new line in the static*/
int	ft_nlcheck(char *staticstr)
{
	int	i;

	i = 0;
	while (staticstr[i])
	{
		if (staticstr[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*a simple strlen*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*things to execute when you hit the end of file*/
void	*eof(char **staticstr)
{
	free(*staticstr);
	*staticstr = 0;
	return (NULL);
}
