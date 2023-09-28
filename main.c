/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liam <liam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 06:01:12 by liam              #+#    #+#             */
/*   Updated: 2023/09/28 14:53:27 by liam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_datastr *data, char *reason)
{
	ft_printf("%s\n", reason);
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

void	start(t_datastr *data)
{
	data->col = 0;
	data->x = 0;
	data->y = 0;
	data->mov = 0;
	data->ccol = 0;
	checkmap(data);
	savemap(data, 0, 0);
	savecolormap(data, 0, 0);
	load(data);
	grassflood(data);
	if (pathcheck(data, data->y / TILE, data->x / TILE) == 0
		|| data->ccol != data->col)
	{
		ft_close(data, "NO VALID PATH\n");
	}
	else
		ft_printf("yippy\n");
	mlx_put_image_to_window(data->fenetre,
		data->new_fenetre, data->image, data->x, data->y);
}

int	main(void)
{
	t_datastr	data;

	data.col = 0;
	data.x = 0;
	data.y = 0;
	data.mov = 0;
	checkmap(&data);
	data.fenetre = mlx_init();
	data.new_fenetre = mlx_new_window(data.fenetre,
			(data.len - 1) * TILE, data.hei * TILE, "test");
	start(&data);
	mlx_key_hook(data.new_fenetre, on_keypress, &data);
	mlx_hook(data.new_fenetre, 17, 1L < 17, ft_close, &data);
	mlx_loop(data.fenetre);
}
