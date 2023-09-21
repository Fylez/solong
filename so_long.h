#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H


# include <stdio.h>
# include "include/libftfin/libft.h"
# include <mlx.h>

# define TILE 32
# define XY (j * TILE), (i * TILE)
# define FN data.fenetre
# define X data->x
# define Y data->y
# define FENETRE data->fenetre, data->new_fenetre
# define MAP_HEIGHT data->hei
# define MAP_WIDTH data->len


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

void checkmap(teststr *data, int fd);
void savemap(teststr *data, int fd);
void grassflood(teststr *data, int fd);

#endif