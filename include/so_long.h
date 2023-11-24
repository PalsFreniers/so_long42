/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:56:43 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/24 19:45:37 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "errors.h"
# include "file_utils.h"
# include "mlxw.h"

# define CELL_SIZE 64

# define MAP_EMPTY '0'
# define MAP_WALL '1'
# define MAP_COLLECTIBLE 'C'
# define MAP_EXIT 'E'
# define MAP_PLAYER 'P'
# define MAP_ENEMY 'X'

# define FLAG_ERROR 0b00000001
# define FLAG_END_OF_GAME 0b00000010
# define FLAG_ENEMY_MOVE 0b00000100
# define FLAG_PAUSE 0b00001000
# define FLAG_WON 0b00010000
# define FLAG_KILLED 0b00100000

struct					s_map
{
	size_t				width;
	size_t				height;
	size_t				col_nbr;
	char				*map;
};

struct					s_flood_fill
{
	char				*cache;
	size_t				score;
	int					exit;
};

struct					s_v2
{
	size_t				x;
	size_t				y;
};

struct					s_player
{
	struct s_img_dat	ctx;
	int					x;
	int					y;
	int					left;
	int					current_frame;
	struct s_image		frames[6];
};

struct					s_exit
{
	struct s_image		current;
	struct s_v2			pos;
	struct s_image		frames[2];
};

struct					s_enemy
{
	struct s_img_dat	ctx;
	struct s_v2			*poss;
	struct s_image		frames[6];
	int					nb;
	int					current_frame;
};

struct					s_so_long
{
	struct s_mlx		mlx;
	struct s_map		map;
	struct s_image		bg;
	struct s_image		wall[4];
	struct s_exit		exit;
	struct s_image		collectible;
	struct s_image		numbers[10];
	struct s_player		player;
	struct s_enemy		enemy;
	struct s_image		end_screen;
	struct s_image		killed_screen;
        int *e_cache;
	int					can_exit;
	size_t				keypresses;
	size_t				score;
	int					ticks;
	char				flags;
};

void					map_render(struct s_so_long *game, size_t x, size_t y);
void					render_map(struct s_so_long *game);
char					*get_file(int c, char **v);
char					*map_at(struct s_so_long *game, int x, int y);
void					refresh_numbers(struct s_so_long *game);
void					refresh_score(struct s_so_long *game);
void					refresh_player_cells(struct s_so_long *game,
							struct s_v2 a, struct s_v2 b);
void					map_parse(struct s_so_long *game, char *filePath);
int						key_pressed(int code, struct s_so_long *game);
void					so_long_unleak(struct s_so_long game);
int						f_loop(struct s_so_long *game);
void					init_game(struct s_so_long *game);
void					player_add(struct s_so_long *game, int *player,
							struct s_v2 pos);
void					player_move(struct s_so_long *game, int x, int y);
void					exit_add(struct s_so_long *game, int *exit,
							struct s_v2 pos);
void					map_error(struct s_so_long *game, int code);
void					check_borders(struct s_so_long *game);
void					ff_check(struct s_so_long *game);
void					init_enemies(struct s_so_long *game);

#endif // SO_LONG_H
