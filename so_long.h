/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liam <liam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:49:04 by liam              #+#    #+#             */
/*   Updated: 2023/10/11 16:04:58 by liam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "include/libftfin/libft.h"
# include <mlx.h>
# define TILE 32

typedef struct data
{
	void	*fenetre;
	void	*new_fenetre;
	void	*image;
	void	*rien;
	void	*wall;
	void	*collectible;
	void	*end;
	int		x;
	int		y;
	int		len;
	int		hei;
	char	**map;
	char	**cmap;
	int		col;
	int		ccol;
	int		pexist;
	int		mov;
	int		fd;
	char	*line;
}	t_datastr;

void	checkmap(t_datastr *data);
void	savemap(t_datastr *data, int i, int j);
void	grassflood(t_datastr *data);
void	casecheck(t_datastr *data, int i, int j);
void	move(t_datastr *data, int rx, int ry);
int		on_keypress(int pressedkey, t_datastr *data);
int		ft_close(t_datastr *data, char *reason);
void	start(t_datastr *data);
void	savecolormap(t_datastr *data, int i, int j);
int		pathcheck(t_datastr *data, int j, int i);
void	printmap(char **map);
int		cross(t_datastr *data);


#endif