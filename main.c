/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liam <liam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 06:01:12 by liam              #+#    #+#             */
/*   Updated: 2023/09/20 15:26:47 by liam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(teststr *data)
{
	mlx_destroy_window(FENETRE);
	exit(0);
}

void	casecheck(teststr *data, int i, int j)
{
	if (data->map[j][i] == 'C')
	{
		data->col--;
		data->map[j][i] = '0';
		printf("Nombre de Collectible restant: %d \n", data->col);
	}
	if (data->map[j][i] == 'E' && data->col == 0)
	{
		mlx_destroy_window(FENETRE);
		exit(0);
	}
}

void	move(teststr *data, int rx, int ry)
{
	int i;
	int j;

	i = X / TILE;
	j = Y / TILE;
	if (data->map[j + ry][i + rx] != '1')
	{
		if (data->map[j + ry][i + rx] != 'E' || data->col == 0)
		{
			data->mov++;
			mlx_put_image_to_window(FENETRE, data->rien, X, Y);
			X = X + (rx * TILE);
			Y = Y + (ry * TILE);
			mlx_put_image_to_window(FENETRE, data->image, X, Y);
			casecheck(data, i + rx, j + ry);
			printf("Nombre de mouvement: %d \n", data->mov);
		}
	}
}

int	on_keypress(int pressedkey, teststr *data)
{	
	if (pressedkey == 65307)
		ft_close(data);
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

int load(teststr *data)
{
	int width;
	int height;
	data->image = mlx_xpm_file_to_image(data->fenetre, 
		"assets/plant.xpm", &width, &height);
	data->rien = mlx_xpm_file_to_image(data->fenetre, 
		"assets/rien.xpm", &width, &height);
	data->wall = mlx_xpm_file_to_image(data->fenetre, 
		"assets/wall.xpm", &width, &height);
	data->collectible = mlx_xpm_file_to_image(data->fenetre, 
		"assets/collectible.xpm", &width, &height);
	data->end = mlx_xpm_file_to_image(data->fenetre, 
		"assets/end.xpm", &width, &height);
}

int	main(void)
{
	
	teststr	data;
	int		fd;

	fd = open("map/test.ber", O_RDWR);
	data.col = 0;
	data.x = 0;
	data.y = 0;
	data.mov = 0;
	checkmap(&data, fd);
	close(fd);
	fd = open("map/test.ber", O_RDWR);
	savemap(&data, fd);
	close(fd);
	fd = open("map/test.ber", O_RDWR);
	data.fenetre = mlx_init();
	data.new_fenetre = mlx_new_window(data.fenetre, (data.len - 1) * TILE, data.hei * TILE, "test");
	load(&data);
	grassflood(&data, fd);
	mlx_put_image_to_window(data.fenetre, data.new_fenetre, data.image, data.x, data.y);
	mlx_key_hook(data.new_fenetre, on_keypress, &data);
	mlx_hook(data.new_fenetre, 17, 1L < 17, ft_close, &data);
	mlx_loop(data.fenetre);
	close(fd);
}
