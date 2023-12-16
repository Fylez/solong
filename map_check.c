/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:37:50 by liam              #+#    #+#             */
/*   Updated: 2023/12/16 16:21:20 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	casecolourcheck(char c, t_datastr *data)
{
	if (c == '1')
		return (0);
	else if (c == 'E')
		return (1);
	else
	{
		if (c == 'C')
			data->ccol++;
		return (2);
	}
}

void	savecolormap(t_datastr *data, int i, int j)
{
	data->fd = open(data->name, O_RDWR);
	data -> cmap = malloc((data->hei + 1) * (sizeof(char *)));
	if (!data->cmap)
		ft_close(data, "ERREUR MALLOC");
	data->line = get_next_line(data->fd);
	while (data->line)
	{
		data -> cmap[i] = malloc(data -> len * sizeof(char) + 1);
		if (!data->cmap[i])
			ft_close(data, "ERREUR MALLOC");
		while (j < data->len)
		{
			data->cmap[i][j] = data->line[j];
			j++;
		}
		data->cmap[i][j] = '\0';
		free(data->line);
		data->line = get_next_line(data->fd);
		j = 0;
		i++;
	}
	free(data->line);
	data->cmap[i] = '\0';
	close(data->fd);
}

void	printmap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

int	pathcheck(t_datastr *data, int j, int i)
{
	int	found;

	found = 0;
	data->cmap[j][i] = '1';
	if (casecolourcheck(data->cmap[j + 1][i], data) == 2)
		found = found | pathcheck(data, j + 1, i);
	else if (casecolourcheck(data->cmap[j + 1][i], data) == 1)
		found = 1;
	if (casecolourcheck(data->cmap[j - 1][i], data) == 2)
		found = found | pathcheck(data, j - 1, i);
	else if (casecolourcheck(data->cmap[j - 1][i], data) == 1)
		found = 1;
	if (casecolourcheck(data->cmap[j][i + 1], data) == 2)
		found = found | pathcheck(data, j, i + 1);
	else if (casecolourcheck(data->cmap[j][i + 1], data) == 1)
		found = 1;
	if (casecolourcheck(data->cmap[j][i - 1], data) == 2)
		found = found | pathcheck(data, j, i - 1);
	else if (casecolourcheck(data->cmap[j][i - 1], data) == 1)
		found = 1;
	return (found);
}
