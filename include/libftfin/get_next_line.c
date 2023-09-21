/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fylez <fylez@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:42:25 by fylez             #+#    #+#             */
/*   Updated: 2023/07/25 18:42:25 by fylez            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Switch temp and staticstr pointer*/
void	ft_switch(char **staticstr, char *temp, int j, int i)
{
	temp = malloc (sizeof(char) * (BUFFER_SIZE + ft_strlen(*staticstr) + 1));
	if (!temp)
		return ;
	while ((*staticstr)[i])
	{
		temp[j] = (*staticstr)[i];
		i++;
		j++;
	}
	free(*staticstr);
	*staticstr = temp;
	(*staticstr)[j] = '\0';
}

/*Cut the return string and keep the leftover for the next call*/
void	ft_cut(char **staticstr, char *temp, char *returnstr)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while ((*staticstr)[i] != '\n' && (*staticstr)[i] != '\0')
	{
		returnstr[i] = (*staticstr)[i];
		i++;
	}
	if ((*staticstr)[i] == '\n')
	{
		returnstr[i] = (*staticstr)[i];
		i++;
	}
	returnstr[i] = '\0';
	ft_switch(staticstr, temp, j, i);
}

/*add buffer to the static variable*/
void	ft_conc(char *buffer, char **staticstr, char *temp)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while ((*staticstr)[j] != '\0')
			j++;
	while (buffer[i] != '\0')
	{
		(*staticstr)[j] = buffer[i];
		i++;
		j++;
	}
	(*staticstr)[j] = '\0';
	ft_switch(staticstr, temp, 0, 0);
}

int	gnl2(char **staticstr, char *temp, int fd)
{
	char			*buffer;
	int				nbbyte;
	int				found;

	found = 0;
	while (found == 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		nbbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbbyte == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[nbbyte] = '\0';
		ft_conc(buffer, staticstr, temp);
		free(buffer);
		if (ft_nlcheck(*staticstr) == 1 || nbbyte == 0)
			found = 1;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*staticstr;
	char			*temp;
	char			*returnstr;

	temp = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!staticstr)
	{
		staticstr = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!staticstr)
			return (NULL);
		staticstr[0] = '\0';
	}
	if (gnl2(&staticstr, temp, fd) == 0)
		return (NULL);
	if (staticstr[0] != '\0')
	{
		returnstr = malloc(sizeof(char) * (ft_strlen(staticstr) + 1));
		ft_cut(&staticstr, temp, returnstr);
	}
	else
		return (eof(&staticstr));
	return (returnstr);
}

/*
#include <fcntl.h>
int main()
{
	char    *line;
	int     fd;

	fd = open("tests/two_lines_with_nl", O_RDWR);
	line = (char *)1;

		line = get_next_line(fd);
			printf("%s", line);
			free(line);
					line = get_next_line(fd);
			printf("%s", line);
			free(line);
					line = get_next_line(fd);
			printf("%s", line);
			free(line);
					line = get_next_line(fd);
			printf("%s", line);
			free(line);
	return (0);
}*/