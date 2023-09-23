/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fylez <fylez@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:49:04 by liam              #+#    #+#             */
/*   Updated: 2023/09/23 14:15:59 by fylez            ###   ########.fr       */
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
	int		col;
	int		mov;
	int		fd;
}	t_datastr;

void	checkmap(t_datastr *data);
void	savemap(t_datastr *data);
void	grassflood(t_datastr *data);
void	casecheck(t_datastr *data, int i, int j);
void	move(t_datastr *data, int rx, int ry);
int		on_keypress(int pressedkey, t_datastr *data);
int		ft_close(t_datastr *data);
void	start(t_datastr *data);


#endif