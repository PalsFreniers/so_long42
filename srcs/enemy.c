/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:16:40 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/26 08:11:21 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	enemy_generate(struct s_so_long *game, int i)
{
	int	x;
	int	y;
	int	ok;

	ok = 0;
	while (!ok)
	{
		x = ft_rand(1, game->map.width - 1);
		y = ft_rand(1, game->map.height - 1);
		if (*map_at(game, x, y) == MAP_EMPTY || *map_at(game, x,
				y) == MAP_COLLECTIBLE)
		{
			if (*map_at(game, x, y) == MAP_COLLECTIBLE)
				game->enemy.has_col[i] = 1;
			else
				game->enemy.has_col[i] = 0;
			*map_at(game, x, y) = MAP_ENEMY;
			game->enemy.poss[i] = (struct s_v2){
				.x = x,
				.y = y,
			};
			ok = 1;
		}
	}
}

void	init_enemies(struct s_so_long *game)
{
	int	i;

	game->enemy.nb = game->map.col_nbr / 4;
	if (game->enemy.nb == 0)
		game->enemy.nb = 1;
	game->enemy.poss = ft_calloc(game->enemy.nb, sizeof(struct s_v2));
	if (!game->enemy.poss)
		map_error(game, MALLOC_ERROR);
	game->enemy.has_col = ft_calloc(game->enemy.nb, sizeof(int));
	if (!game->enemy.has_col)
	{
		free(game->enemy.poss);
		map_error(game, MALLOC_ERROR);
	}
	i = 0;
	while (i < game->enemy.nb)
	{
		enemy_generate(game, i);
		i++;
	}
}

int	get_less_around(struct s_so_long *game, struct s_v2 pos)
{
	unsigned int	up;
	unsigned int	down;
	unsigned int	left;
	unsigned int	right;

	up = game->enemy.wm[pos.x + (pos.y - 1) * game->map.width];
	down = game->enemy.wm[pos.x + (pos.y + 1) * game->map.width];
	left = game->enemy.wm[(pos.x - 1) + pos.y * game->map.width];
	right = game->enemy.wm[(pos.x + 1) + pos.y * game->map.width];
	return (supra_min(up, down, left, right));
}

void	ff_gen_wm(struct s_so_long *game, struct s_v2 pos, int prec)
{
	char	m_pos;
	int		less;
	int		new;

	if (game->enemy.wm[pos.x + pos.y * game->map.width] == -1)
		new = 1;
	else
		new = 0;
	m_pos = *map_at(game, pos.x, pos.y);
	if (m_pos == MAP_WALL || m_pos == MAP_EXIT || m_pos == MAP_ENEMY)
		return ;
	less = 0;
	if (m_pos != MAP_PLAYER)
	{
		less = get_less_around(game, pos);
		if (less + 1 > prec)
			less = prec + 1;
		else
			less = less + 1;
	}
	game->enemy.wm[pos.x + pos.y * game->map.width] = less;
	if (new)
		launch_batch(game, pos, less);
}

void	gen_weightmap(struct s_so_long *game)
{
	if (game->enemy.wm)
		free(game->enemy.wm);
	game->enemy.wm = (int *)malloc((game->map.width * game->map.height + 1)
			* sizeof(int));
	if (!game->enemy.wm)
	{
		so_long_unleak(*game);
		handle_error(MALLOC_ERROR);
	}
	ft_memset(game->enemy.wm, -1, game->map.width * game->map.height
		* sizeof(int));
	game->enemy.wm[game->player.x + game->player.y * game->map.width] = 0;
	launch_batch(game, (struct s_v2){game->player.x, game->player.y}, 0);
}
