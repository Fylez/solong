/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liam <liam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 05:54:58 by liam              #+#    #+#             */
/*   Updated: 2023/10/11 15:55:19 by liam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkxborder(char *line, t_datastr *data)
{
	int	i;

	i = 0;
	while (i < data->len - 1)
	{
		if (line[i] != '1')
		{
			free(line);
			while (line)
			{
				line = get_next_line(data->fd);
				free(line);
			}
			close(data->fd);
			ft_printf("INVALID MAP\n");
			exit(0);
		}
		i++;
	}
}

void	checkmap(t_datastr *data)
{
	char	*line;

	data->fd = open("map/test.ber", O_RDWR);
	data -> hei = 0;
	line = get_next_line(data->fd);
	if (!line)
		exit(0);
	data->len = ft_strlen(line);
	checkxborder(line, data);
	while (line)
	{
		data->hei = data->hei + 1;
		if (ft_strlen(line) != data->len
			|| line[0] != '1' || line[data->len - 2] != '1')
		{
			free(line);
			close(data->fd);
			ft_printf("INVALID MAP\n");
			exit(0);
		}
		free(line);
		line = get_next_line(data->fd);
	}
	free(line);
	close(data->fd);
}

void	savemap(t_datastr *data, int i, int j)
{
	data->fd = open("map/test.ber", O_RDWR);
	data -> map = malloc(data->hei * (sizeof(char *) + 1));
	if (!data->map)
		ft_close(data, "ERREUR MALLOC");
	data->line = get_next_line(data->fd);
	while (data->line)
	{
		data -> map[i] = malloc(data -> len * (sizeof(char) + 1));
		if (!data->map[i])
			ft_close(data, "ERREUR MALLOC");
		while (j < data->len)
		{
			data->map[i][j] = data->line[j];
			j++;
		}
		free(data->line);
		data->map[i][j] = '\0';
		data->line = get_next_line(data->fd);
		j = (i++, 0);
	}
	free(data->line);
	checkxborder(data->map[i - 1], data);
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
		data->pexist++;
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

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			tileread(data, data->map[i][j], j, i);
			j++;
		}
		i++;
		j = 0;
	}
}
