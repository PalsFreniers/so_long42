/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:36:23 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/26 08:04:34 by tdelage          ###   ########.fr       */
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

void	init_enemy(struct s_so_long *game)
{
	game->enemy.frames[0] = s_image_create_xpm(game->mlx, "textures/E0.xpm");
	game->enemy.frames[1] = s_image_create_xpm(game->mlx, "textures/E1.xpm");
	game->enemy.frames[2] = s_image_create_xpm(game->mlx, "textures/E2.xpm");
	game->enemy.frames[3] = s_image_create_xpm(game->mlx, "textures/E3.xpm");
	game->enemy.frames[4] = s_image_create_xpm(game->mlx, "textures/E4.xpm");
	game->enemy.frames[5] = s_image_create_xpm(game->mlx, "textures/E5.xpm");
	game->enemy.ctx = game->enemy.frames[0].ctx;
	game->enemy.current_frame = 0;
	game->enemy.wm = NULL;
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

void	init_walls_end_pos(struct s_so_long *game)
{
	game->wall[0] = s_image_create_xpm(game->mlx, "textures/wall0.xpm");
	game->wall[1] = s_image_create_xpm(game->mlx, "textures/wall1.xpm");
	game->wall[2] = s_image_create_xpm(game->mlx, "textures/wall2.xpm");
	game->wall[3] = s_image_create_xpm(game->mlx, "textures/wall3.xpm");
	game->end_screen.x = ((game->map.width * CELL_SIZE) / 2) - 96;
	game->end_screen.y = ((game->map.height * CELL_SIZE) / 2) - 96;
	game->killed_screen.x = game->end_screen.x;
	game->killed_screen.y = game->end_screen.y;
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
			CELL_SIZE * game->map.height, "So Long"));
	init_nbrs(game);
	init_player(game);
	game->end_screen = s_image_create_xpm(game->mlx, "textures/win_screen.xpm");
	game->killed_screen = s_image_create_xpm(game->mlx,
			"textures/death_screen.xpm");
	game->bg = s_image_create_xpm(game->mlx, "textures/background.xpm");
	game->collectible = s_image_create_xpm(game->mlx, "textures/food.xpm");
	game->exit.frames[1] = s_image_create_xpm(game->mlx,
			"textures/trap_open.xpm");
	game->exit.frames[0] = s_image_create_xpm(game->mlx,
			"textures/trap_clse.xpm");
	game->exit.current = game->exit.frames[0];
	init_walls_end_pos(game);
	init_enemy(game);
}
