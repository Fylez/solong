/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liam <liam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:59:51 by liam              #+#    #+#             */
/*   Updated: 2023/10/11 16:12:52 by liam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	casecheck(t_datastr *data, int i, int j)
{
	if (data->map[j][i] == 'C')
	{
		data->col--;
		data->map[j][i] = '0';
		ft_printf("Nombre de Collectible restant: %d \n", data->col);
	}
	if (data->map[j][i] == 'E' && data->col == 0)
	{
		mlx_destroy_window(data->fenetre, data->new_fenetre);
		exit(0);
	}
}

void	move(t_datastr *data, int rx, int ry)
{
	int	i;
	int	j;

	i = data->x / TILE;
	j = data->y / TILE;
	if (data->map[j + ry][i + rx] != '1')
	{
		if (data->map[j + ry][i + rx] != 'E' || data->col == 0)
		{
			data->mov++;
			mlx_put_image_to_window(data->fenetre,
				data->new_fenetre, data->rien, data->x, data->y);
			data->x = data->x + (rx * TILE);
			data->y = data->y + (ry * TILE);
			mlx_put_image_to_window(data->fenetre,
				data->new_fenetre, data->image, data->x, data->y);
			casecheck(data, i + rx, j + ry);
			ft_printf("Nombre de mouvement: %d \n", data->mov);
		}
	}
}

int	on_keypress(int pressedkey, t_datastr *data)
{
	if (pressedkey == 65307)
		ft_close(data, "ESCAPE KEY PRESSED");
	if (pressedkey == 'w')
		move(data, 0, -1);
	if (pressedkey == 's')
		move(data, 0, 1);
	if (pressedkey == 'd')
		move(data, 1, 0);
	if (pressedkey == 'a')
		move(data, -1, 0);
	return (0);
}
