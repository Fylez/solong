/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liam <liam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:37:37 by liam              #+#    #+#             */
/*   Updated: 2023/10/11 15:56:57 by liam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
