/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fylez <fylez@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:26:10 by fylez             #+#    #+#             */
/*   Updated: 2023/09/21 15:46:01 by fylez            ###   ########.fr       */
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

/*things to execute when you hit the end of file*/
void	*eof(char **staticstr)
{
	free(*staticstr);
	*staticstr = 0;
	return (NULL);
}
