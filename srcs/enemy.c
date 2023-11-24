/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:16:40 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/24 20:04:45 by tdelage          ###   ########.fr       */
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
		if (*map_at(game, x, y) == MAP_EMPTY)
		{
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
	i = 0;
	while (i < game->enemy.nb)
	{
		enemy_generate(game, i);
                i++;
	}
}
