/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:36:23 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/20 11:04:57 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_player(struct s_so_long *game)
{
	game->player.frames[0] = s_image_create_xpm(game->mlx,
			"textures/plyerL0.xpm");
	game->player.frames[1] = s_image_create_xpm(game->mlx,
			"textures/plyerL1.xpm");
	game->player.frames[2] = s_image_create_xpm(game->mlx,
			"textures/plyerL2.xpm");
	game->player.frames[3] = s_image_create_xpm(game->mlx,
			"textures/plyerR0.xpm");
	game->player.frames[4] = s_image_create_xpm(game->mlx,
			"textures/plyerR1.xpm");
	game->player.frames[5] = s_image_create_xpm(game->mlx,
			"textures/plyerR2.xpm");
	game->player.left = 0;
	game->player.ctx = game->player.frames[0].ctx;
	game->player.current_frame = 0;
}

void	init_nbrs(struct s_so_long *game)
{
	game->numbers[0] = s_image_create_xpm(game->mlx, "textures/0.xpm");
	game->numbers[1] = s_image_create_xpm(game->mlx, "textures/1.xpm");
	game->numbers[2] = s_image_create_xpm(game->mlx, "textures/2.xpm");
	game->numbers[3] = s_image_create_xpm(game->mlx, "textures/3.xpm");
	game->numbers[4] = s_image_create_xpm(game->mlx, "textures/4.xpm");
	game->numbers[5] = s_image_create_xpm(game->mlx, "textures/5.xpm");
	game->numbers[6] = s_image_create_xpm(game->mlx, "textures/6.xpm");
	game->numbers[7] = s_image_create_xpm(game->mlx, "textures/7.xpm");
	game->numbers[8] = s_image_create_xpm(game->mlx, "textures/8.xpm");
	game->numbers[9] = s_image_create_xpm(game->mlx, "textures/9.xpm");
}

void	init_game(struct s_so_long *game)
{
	game->score = 0;
	game->keypresses = 0;
	game->flags = 0;
	game->can_exit = 0;
	game->ticks = 0;
	mlxw_create_context(&game->mlx);
	mlxw_create_window(&game->mlx, s_window_create(CELL_SIZE * game->map.width,
			CELL_SIZE * game->map.height, "First window"));
	init_nbrs(game);
	init_player(game);
	game->end_screen = s_image_create_xpm(game->mlx, "textures/win_screen.xpm");
	game->bg = s_image_create_xpm(game->mlx, "textures/background.xpm");
	game->collectible = s_image_create_xpm(game->mlx, "textures/food.xpm");
	game->wall = s_image_create_xpm(game->mlx, "textures/wall.xpm");
	game->exit.frames[1] = s_image_create_xpm(game->mlx,
			"textures/trap_open.xpm");
	game->exit.frames[0] = s_image_create_xpm(game->mlx,
			"textures/trap_clse.xpm");
	game->exit.current = game->exit.frames[0];
	game->end_screen.x = ((game->map.width * CELL_SIZE) / 2) - 96;
	game->end_screen.y = ((game->map.height * CELL_SIZE) / 2) - 96;
}

void	so_long_unleak(struct s_so_long game)
{
	int	i;

	s_image_destroy(game.mlx, game.bg);
	i = 0;
	while (i < 6)
	{
		s_image_destroy(game.mlx, game.player.frames[i]);
		i++;
	}
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