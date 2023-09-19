#include <mlx.h>
#include <stdio.h>
# define tilesize 32
# define MAP_HEIGHT data->hei
# define MAP_WIDTH data->len
#include "include/get_next_line.h"
typedef struct test
{
	void *fenetre;
	void *new_fenetre;
	void *image;
	void *rien;
	void *wall;
	void *collectible;
	void *end;
	int x;
	int y;
	int len;
	int hei;
	char **map;
	int col;
	int mov;
} teststr;

void checkmap(teststr *data, int fd)
{
	data -> hei = 0;
	char *line;
	line = get_next_line(fd);
	if(!line)
		exit(0);
	data->len = ft_strlen(line);
	while(line)
	{
		printf("%s\n", line);
		data->hei = data->hei + 1;
		if (ft_strlen(line) != data->len)
		{
			printf("%s\n", "invalid map");
			exit(0);
		}

		free(line);
		line = get_next_line(fd);
	}
	printf("%s\n", "endof");

}

void savemap(teststr *data, int fd)
{
	int i;
	int j;
	char *line;
	i = 0;
	j = 0;
	data -> map = malloc(data->hei * (sizeof(char *) + 1));
	if(!data->map)
			return;
	while(i < MAP_HEIGHT)
	{
		data -> map[i] = malloc(data -> len * sizeof(char));
		if(!data->map[i])
			return;
		line = get_next_line(fd);
		while(j < MAP_WIDTH)
		{
			data->map[i][j] = line[j];
			j++;
		}
		free(line);
		i++;
		j = 0;
	}
	data->map[i] = '\0';

}

void grassflood(teststr *data, int fd)
{
	int i;
	int j;

	i = 0;
	j = 0;
	char *line;


	while(i < MAP_HEIGHT)
	{
		line = get_next_line(fd);
		while(j < MAP_WIDTH)
		{
			if (line[j] == '1')
				mlx_put_image_to_window(data->fenetre, data->new_fenetre, data->wall, (j * tilesize), (i * tilesize));
			if (line[j] == '0')
				mlx_put_image_to_window(data->fenetre, data->new_fenetre, data->rien, (j * tilesize), (i * tilesize));
			if(line[j] == 'C')
			{
				mlx_put_image_to_window(data->fenetre, data->new_fenetre, data->collectible, (j * tilesize), (i * tilesize));
				data->col++;
			}
			if(line[j] == 'P')
			{
				data->x = j * tilesize;
				data->y = i * tilesize;
			}
			if(line[j] == 'E')
				mlx_put_image_to_window(data->fenetre, data->new_fenetre, data->end, (j * tilesize), (i * tilesize));
			j++;
		}
		free(line);
		i++;
		j = 0;
	}
}

int on_keypress(int pressedkey, teststr *data)
{
	if (pressedkey == 65307)
	{
		mlx_destroy_window(data->fenetre, data->new_fenetre);
		exit(0);
	}
	if (pressedkey == 'w' && data->y >= tilesize)
	{
		if (data->map[(data->y - tilesize) / tilesize][data->x / tilesize] != '1')
		{
			data->mov++;
			mlx_put_image_to_window(data->fenetre, data->new_fenetre, data->rien, data->x, data->y);
			data->y = data->y - (1 * tilesize);
			mlx_put_image_to_window(data->fenetre, data->new_fenetre, data->image, data->x, data->y);
		}
	}


	if(pressedkey == 's' && data->y <= ((MAP_HEIGHT - 2) * tilesize))
	{
		if(data->map[(data->y + tilesize) / tilesize][data->x / tilesize] != '1')
		{
			data->mov++;
			mlx_put_image_to_window(data->fenetre, data->new_fenetre, data->rien, data->x, data->y);
			data->y = data->y + (1 * tilesize);
			mlx_put_image_to_window(data->fenetre, data->new_fenetre, data->image, data->x, data->y);
		}
	}


	if(pressedkey == 'd' && data->x <= ((MAP_WIDTH - 3) * tilesize))
	{
		if(data->map[data->y / tilesize][(data->x + tilesize) / tilesize] != '1')
		{
			data->mov++;
			mlx_put_image_to_window(data->fenetre, data->new_fenetre, data->rien, data->x, data->y);
			data->x = data->x + (1 * tilesize);
			mlx_put_image_to_window(data->fenetre, data->new_fenetre, data->image, data->x, data->y);
		}
	}


	if(pressedkey == 'a' && data->x >= tilesize)
	{
		if(data->map[data->y / tilesize][(data->x - tilesize) / tilesize] != '1')
		{
			data->mov++;
			mlx_put_image_to_window(data->fenetre, data->new_fenetre, data->rien, data->x, data->y);
			data->x = data->x - (1 * tilesize);
			mlx_put_image_to_window(data->fenetre, data->new_fenetre, data->image, data->x, data->y);
		}
	}
	if(data->map[data->y / tilesize][(data->x) / tilesize] == 'C')
	{
		data->col--;
		data->map[data->y / tilesize][(data->x) / tilesize] = '0';
	}
	if(data->map[data->y / tilesize][(data->x) / tilesize] == 'E' && data->col == 0)
	{
		mlx_destroy_window(data->fenetre, data->new_fenetre);
		exit(0);
	}
	printf("Nombre de Collectible restant: %d \n", data->col);
	printf("Nombre de mouvement: %d \n", data->mov);
	return (0);
}

int	main(void)
{
	int width;
	int height;
	teststr data;
	int fd;

	fd = open("map/test.ber", O_RDWR);
	printf("%c\n", '0');
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
	int i;
	i = 0;
	while(data.map[i])
	{
		printf("%s", data.map[i]);
		i++;
	}
	printf("%d\n", data.hei);
	printf("%d\n", data.len);
	data.new_fenetre = mlx_new_window(data.fenetre, (data.len - 1) * tilesize, data.hei * tilesize, "test");
	data.image = mlx_xpm_file_to_image(data.fenetre, "assets/plant.xpm", &width, &height);
	data.rien = mlx_xpm_file_to_image(data.fenetre, "assets/rien.xpm", &width, &height);
	data.wall = mlx_xpm_file_to_image(data.fenetre, "assets/wall.xpm", &width, &height);
	data.collectible = mlx_xpm_file_to_image(data.fenetre, "assets/collectible.xpm", &width, &height);
	data.end = mlx_xpm_file_to_image(data.fenetre, "assets/end.xpm", &width, &height);
	grassflood(&data, fd); 
	mlx_put_image_to_window(data.fenetre, data.new_fenetre, data.image, data.x, data.y); //DONT WORK
	mlx_key_hook(data.new_fenetre, on_keypress, &data);
	mlx_loop(data.fenetre);
	close(fd);
}
