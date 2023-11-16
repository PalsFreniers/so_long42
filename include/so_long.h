/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:56:43 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/15 21:26:40 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "file_utils.h"
#include "errors.h"
# include "mlxw.h"

# define CELL_SIZE 64

# define MAP_EMPTY '0'
# define MAP_WALL '1'
# define MAP_COLLECTIBLE 'C'
# define MAP_EXIT 'E'
# define MAP_PLAYER 'P'

# define FLAG_ERROR 0b00000001
# define FLAG_END_OF_GAME 0b00000010
# define FLAG_ENEMY_MOVE 0b00000100
# define FLAG_PAUSE 0b00001000


struct					s_map
{
	int					width;
	int					height;
        int col_nbr;
	char				*map;
};

struct					s_player
{
	struct s_img_dat	ctx;
	int					x;
	int					y;
	struct s_img_dat	frames[1];
};

struct s_exit {
        struct s_image current;
        int x;
        int y;
        struct s_image frames[2];
};

struct					s_so_long
{
	struct s_mlx		mlx;
	struct s_map		map;
	struct s_image		bg;
	struct s_image		wall;
	struct s_exit		exit;
	struct s_image		collectible;
	struct s_image		numbers[10];
	struct s_player		player;
        int can_exit;
	int					keypresses;
	int					score;
	char				flags;
};

void					map_render(struct s_so_long *game, int x, int y);
void					render_map(struct s_so_long *game);
void					get_args(int c, char **v, struct s_so_long *game);

#endif // SO_LONG_H
