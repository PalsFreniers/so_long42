/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_fini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <tdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 07:52:36 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/26 08:13:43 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	so_long_unleak_entities(struct s_so_long game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		s_image_destroy(game.mlx, game.player.frames[i]);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		s_image_destroy(game.mlx, game.enemy.frames[i]);
		i++;
	}
	if (game.enemy.has_col)
		free(game.enemy.has_col);
	if (game.enemy.wm)
		free(game.enemy.wm);
	if (game.enemy.poss)
		free(game.enemy.poss);
}

void	so_long_unleak(struct s_so_long game)
{
	int	i;

	so_long_unleak_entities(game);
	s_image_destroy(game.mlx, game.bg);
	s_image_destroy(game.mlx, game.collectible);
	i = 0;
	while (i < 4)
		s_image_destroy(game.mlx, game.wall[i++]);
	s_image_destroy(game.mlx, game.exit.frames[0]);
	s_image_destroy(game.mlx, game.exit.frames[1]);
	s_image_destroy(game.mlx, game.end_screen);
	s_image_destroy(game.mlx, game.killed_screen);
	i = 0;
	while (i < 10)
		s_image_destroy(game.mlx, game.numbers[i++]);
	mlxw_destroy_window(game.mlx);
	mlxw_destroy_context(game.mlx);
	if (game.map.map)
		free(game.map.map);
}
