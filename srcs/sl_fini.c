/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_fini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <tdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 07:52:36 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/24 07:53:57 by tdelage          ###   ########.fr       */
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
}

void	so_long_unleak(struct s_so_long game)
{
	int	i;

	so_long_unleak_entities(game);
	s_image_destroy(game.mlx, game.bg);
	s_image_destroy(game.mlx, game.collectible);
	s_image_destroy(game.mlx, game.wall);
	s_image_destroy(game.mlx, game.exit.frames[0]);
	s_image_destroy(game.mlx, game.exit.frames[1]);
	s_image_destroy(game.mlx, game.end_screen);
	i = 0;
	while (i < 10)
	{
		s_image_destroy(game.mlx, game.numbers[i]);
		i++;
	}
	mlxw_destroy_window(game.mlx);
	mlxw_destroy_context(game.mlx);
	free(game.map.map);
}
