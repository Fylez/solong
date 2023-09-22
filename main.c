/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liam <liam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 06:01:12 by liam              #+#    #+#             */
/*   Updated: 2023/09/22 21:02:13 by liam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_datastr *data)
{
	mlx_destroy_window(data->fenetre, data->new_fenetre);
	exit(0);
}

int	load(t_datastr *data)
{
	int	width;
	int	height;

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
	t_datastr	data;
	int			fd;

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
	data.new_fenetre = mlx_new_window(data.fenetre,
			(data.len - 1) * TILE, data.hei * TILE, "test");
	load(&data);
	grassflood(&data, fd);
	mlx_put_image_to_window(data.fenetre,
		data.new_fenetre, data.image, data.x, data.y);
	mlx_key_hook(data.new_fenetre, on_keypress, &data);
	mlx_hook(data.new_fenetre, 17, 1L < 17, ft_close, &data);
	mlx_loop(data.fenetre);
	close(fd);
}
