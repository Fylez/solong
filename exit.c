/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:37:37 by liam              #+#    #+#             */
/*   Updated: 2023/12/16 16:51:10 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	early_quit(t_datastr *data, char *line)
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

void	free_map(t_datastr *data)
{
	int	i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	if (data->cmap != NULL)
	{
		i = 0;
		while (data->cmap[i] != NULL)
		{
			free(data->cmap[i]);
			i++;
		}
		free(data->cmap);
	}
}

void	closewindow(t_datastr *data)
{
	mlx_destroy_image(data->fenetre, data->image);
	mlx_destroy_image(data->fenetre, data->rien);
	mlx_destroy_image(data->fenetre, data->wall);
	mlx_destroy_image(data->fenetre, data->collectible);
	mlx_destroy_image(data->fenetre, data->end);
	mlx_destroy_window(data->fenetre, data->new_fenetre);
	mlx_destroy_display(data->fenetre);
	free(data->fenetre);
}

int	ft_close(t_datastr *data, char *reason)
{
	ft_printf("%s\n", reason);
	closewindow(data);
	free_map(data);
	exit(0);
}

int	cross(t_datastr *data)
{
	ft_close(data, "CROSS CLICKED");
}
