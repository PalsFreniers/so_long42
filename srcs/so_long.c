/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 05:13:41 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/12 13:54:21 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	w_cl(struct s_mlx *mlx)
{
	mlx_loop_end(mlx->ctx);
	return (1);
}

void	draw(struct s_so_long *game)
{
	mlxw_clear(game->mlx);
        render_map(game);
	mlxw_print_img(game->mlx, game->player);
}

int	key_pressed(int keycode, struct s_so_long *game)
{
	if (keycode == K_UP)
		game->player.y -= CELL_SIZE;
	if (keycode == K_DOWN)
		game->player.y += CELL_SIZE;
	if (keycode == K_LEFT)
		game->player.x -= CELL_SIZE;
	if (keycode == K_RIGHT)
		game->player.x += CELL_SIZE;
	draw(game);
	return (1);
}

void	so_long_unleak(struct s_so_long game)
{
	s_image_destroy(game.mlx, game.bg);
	s_image_destroy(game.mlx, game.player);
	mlxw_destroy_window(game.mlx);
	mlxw_destroy_context(game.mlx);
}

int	main(int c, char **v)
{
	struct s_so_long	game;

        get_args(c, v, &game);

	mlxw_create_context(&game.mlx);
	mlxw_create_window(&game.mlx, s_window_create(CELL_SIZE * MAP_WIDTH, CELL_SIZE * MAP_HEIGHT,
			"First window"));
	game.bg = s_image_create_xpm(game.mlx, "assets/Grass.xpm");
	game.player = s_image_create_xpm(game.mlx, "assets/Steak.xpm");
	s_hook_register(game.mlx, s_hook_create(E_DESTROY_NOTIFY, M_NONE, w_cl,
			&game.mlx));
	s_hook_register(game.mlx, s_hook_create(E_KEY_PRESSED, M_KEY_PRESSED,
			key_pressed, &game));
	draw(&game);
	mlx_loop(game.mlx.ctx);
	so_long_unleak(game);
}
