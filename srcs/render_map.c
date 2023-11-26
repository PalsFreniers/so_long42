/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:21:22 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/26 08:04:01 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <printf.h>

void	map_render(struct s_so_long *game, size_t x, size_t y)
{
	size_t			map_w;
	char			*map;
	struct s_image	img;

	map_w = game->map.width;
	map = game->map.map;
	if (map[x + y * map_w] == MAP_WALL)
		img.ctx = game->wall[ft_rand(0, 3)].ctx;
	else if (map[x + y * map_w] == MAP_COLLECTIBLE)
		img.ctx = game->collectible.ctx;
	else if (map[x + y * map_w] == MAP_EXIT)
		img.ctx = game->exit.current.ctx;
	else if (map[x + y * map_w] == MAP_EMPTY)
		img.ctx = game->bg.ctx;
	else if (map[x + y * map_w] == MAP_PLAYER)
		img.ctx = game->player.ctx;
	else if (map[x + y * map_w] == MAP_ENEMY)
		img.ctx = game->enemy.ctx;
	else
		return ;
	img.x = x * CELL_SIZE;
	img.y = y * CELL_SIZE;
	mlxw_print_img(game->mlx, img);
}

void	render_map(struct s_so_long *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	(void)game;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			map_render(game, x, y);
			x++;
		}
		y++;
	}
}

void	refresh_numbers(struct s_so_long *game)
{
	int				tmp;
	struct s_image	nb;

	tmp = game->keypresses;
	nb.ctx = game->numbers[tmp % 10].ctx;
	tmp /= 10;
	nb.y = 0;
	nb.x = 128;
	mlxw_print_img(game->mlx, nb);
	nb.ctx = game->numbers[tmp % 10].ctx;
	tmp /= 10;
	nb.x = 64;
	mlxw_print_img(game->mlx, nb);
	nb.ctx = game->numbers[tmp % 10].ctx;
	nb.x = 0;
	mlxw_print_img(game->mlx, nb);
}

void	refresh_score(struct s_so_long *game)
{
	int				tmp;
	struct s_image	nb;

	tmp = game->score;
	nb.ctx = game->numbers[tmp % 10].ctx;
	tmp /= 10;
	nb.y = game->map.height * 64 - 64;
	nb.x = 128;
	mlxw_print_img(game->mlx, nb);
	nb.ctx = game->numbers[tmp % 10].ctx;
	tmp /= 10;
	nb.x = 64;
	mlxw_print_img(game->mlx, nb);
	nb.ctx = game->numbers[tmp % 10].ctx;
	nb.x = 0;
	mlxw_print_img(game->mlx, nb);
}

void	refresh_player_cells(struct s_so_long *game, struct s_v2 a,
		struct s_v2 b)
{
	game->player.x += a.x;
	game->player.y += a.y;
	game->map.map[b.x + b.y * game->map.width] = MAP_EMPTY;
	*map_at(game, game->player.x, game->player.y) = MAP_PLAYER;
	map_render(game, b.x, b.y);
	map_render(game, game->player.x, game->player.y);
	game->keypresses++;
}
