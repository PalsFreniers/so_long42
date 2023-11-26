/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <tdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:57:56 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/26 08:02:17 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	supra_min(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
	unsigned int	min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	if (min > d)
		min = d;
	if ((int)min == -1)
		min = 0;
	return (min);
}

struct s_v2	getp_less_around(struct s_so_long *game, struct s_v2 pos)
{
	int	min;

	min = get_less_around(game, pos);
	if (min == game->enemy.wm[(pos.x + 1) + pos.y * game->map.width])
		return ((struct s_v2){pos.x + 1, pos.y});
	if (min == game->enemy.wm[(pos.x - 1) + pos.y * game->map.width])
		return ((struct s_v2){pos.x - 1, pos.y});
	if (min == game->enemy.wm[pos.x + (pos.y + 1) * game->map.width])
		return ((struct s_v2){pos.x, pos.y + 1});
	if (min == game->enemy.wm[pos.x + (pos.y - 1) * game->map.width])
		return ((struct s_v2){pos.x, pos.y - 1});
	return (pos);
}

void	enemy_move(struct s_so_long *game, int i, struct s_v2 pos)
{
	char	replace;

	if (*map_at(game, pos.x, pos.y) == MAP_WALL || *map_at(game, pos.x,
			pos.y) == MAP_EXIT || *map_at(game, pos.x, pos.y) == MAP_ENEMY)
		return ;
	if (*map_at(game, pos.x, pos.y) == MAP_PLAYER)
	{
		game->flags |= FLAG_KILLED;
		return ;
	}
	replace = MAP_EMPTY;
	if (game->enemy.has_col[i])
		replace = MAP_COLLECTIBLE;
	*map_at(game, game->enemy.poss[i].x, game->enemy.poss[i].y) = replace;
	if (*map_at(game, pos.x, pos.y) == MAP_COLLECTIBLE)
		game->enemy.has_col[i] = 1;
	else
		game->enemy.has_col[i] = 0;
	*map_at(game, pos.x, pos.y) = MAP_ENEMY;
	map_render(game, pos.x, pos.y);
	map_render(game, game->enemy.poss[i].x, game->enemy.poss[i].y);
	game->enemy.poss[i] = pos;
}

void	launch_batch(struct s_so_long *game, struct s_v2 pos, int less)
{
	if (pos.x < game->map.width - 1)
		ff_gen_wm(game, (struct s_v2){pos.x + 1, pos.y}, less);
	if (pos.x > 0)
		ff_gen_wm(game, (struct s_v2){pos.x - 1, pos.y}, less);
	if (pos.y < game->map.height - 1)
		ff_gen_wm(game, (struct s_v2){pos.x, pos.y + 1}, less);
	if (pos.x > 0)
		ff_gen_wm(game, (struct s_v2){pos.x, pos.y - 1}, less);
}
