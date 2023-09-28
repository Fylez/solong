/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liam <liam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 05:54:58 by liam              #+#    #+#             */
/*   Updated: 2023/09/28 14:54:19 by liam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkmap(t_datastr *data)
{
	char	*line;

	data->fd = open("map/test.ber", O_RDWR);
	data -> hei = 0;
	line = get_next_line(data->fd);
	if (!line)
		exit(0);
	data->len = ft_strlen(line);
	while (line)
	{
		data->hei = data->hei + 1;
		if (ft_strlen(line) != data->len)
		{
			free(line);
			exit(0);
		}
		free(line);
		line = get_next_line(data->fd);
	}
	close(data->fd);
}

void	savemap(t_datastr *data, int i, int j)
{
	char	*line;

	data->fd = open("map/test.ber", O_RDWR);
	data -> map = malloc(data->hei * (sizeof(char *) + 1));
	if (!data->map)
		return ;
	while (i < data->hei)
	{
		data -> map[i] = malloc(data -> len * sizeof(char));
		if (!data->map[i])
			return ;
		line = get_next_line(data->fd);
		while (j < data->len)
		{
			data->map[i][j] = line[j];
			j++;
		}
		free(line);
		j = 0;
		i++;
	}
	data->map[i] = '\0';
	close(data->fd);
}

void	tileread(t_datastr *data, char c, int j, int i)
{
	if (c == '1')
		mlx_put_image_to_window(data->fenetre,
			data->new_fenetre, data->wall, (j * TILE), (i * TILE));
	if (c == '0')
		mlx_put_image_to_window(data->fenetre,
			data->new_fenetre, data->rien, (j * TILE), (i * TILE));
	if (c == 'C')
	{
		mlx_put_image_to_window(data->fenetre,
			data->new_fenetre, data->collectible, (j * TILE), (i * TILE));
		data->col++;
	}
	if (c == 'P')
	{
		data->x = j * TILE;
		data->y = i * TILE;
	}
	if (c == 'E')
		mlx_put_image_to_window(data->fenetre,
			data->new_fenetre, data->end, (j * TILE), (i * TILE));
}

void	grassflood(t_datastr *data)
{
	int		i;
	int		j;
	char	*line;

	data->fd = open("map/test.ber", O_RDWR);
	i = 0;
	j = 0;
	while (i < data->hei)
	{
		line = get_next_line(data->fd);
		while (j < data->len)
		{
			tileread(data, line[j], j, i);
			j++;
		}
		free(line);
		i++;
		j = 0;
	}
	close(data->fd);
}
