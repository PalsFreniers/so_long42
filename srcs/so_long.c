/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 05:13:41 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/14 04:37:13 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <X11/Xlib.h>

int	w_cl(struct s_mlx *mlx)
{
	mlx_loop_end(mlx->ctx);
	return (1);
}

char *so_long_map_at(struct s_so_long *game, int x, int y) {
        struct s_map map = game->map;
        int width = map.width;
        return &(map.map[x + y * width]);
}

void	player_move(struct s_so_long *game, int x, int y)
{
	int	xt;
	int	yt;

	xt = game->player.x;
	yt = game->player.y;
	if (xt + x < 1 || xt + x >= game->map.width - 1 || yt + y < 1 || yt
		+ y >= game->map.height - 1)
		return ;
        if(*so_long_map_at(game, xt + x, yt + y) == MAP_WALL)
                return;
        if(*so_long_map_at(game, xt + x, yt + y) == MAP_COLLECTIBLE)
                game->score++;
	game->player.x += x;
	game->player.y += y;
	game->map.map[xt + yt * game->map.width] = MAP_EMPTY;
	*so_long_map_at(game, game->player.x, game->player.y) = MAP_PLAYER;
	map_render(game, xt, yt);
	map_render(game, game->player.x, game->player.y);
        game->keypresses++;
}

int	key_pressed(int code, struct s_so_long *game)
{
        if(game->flags & FLAG_PAUSE)
                return 1;
	if (code == K_UP || code == K_W)
		player_move(game, 0, -1);
	if (code == K_DOWN || code == K_S)
		player_move(game, 0, 1);
	if (code == K_LEFT || code == K_A)
		player_move(game, -1, 0);
	if (code == K_RIGHT || code == K_D)
		player_move(game, 1, 0);
        if (code == K_ESCAPE)
                w_cl(&game->mlx);
	return (1);
}

void	so_long_unleak(struct s_so_long game)
{
	s_image_destroy(game.mlx, game.bg);
	s_image_destroy(game.mlx, *(struct s_image *)&(game.player));
	mlxw_destroy_window(game.mlx);
	mlxw_destroy_context(game.mlx);
}

int check_cor_flags(struct s_so_long *game) {
        if(game->flags & FLAG_END_OF_GAME)
                game->flags = FLAG_PAUSE;
        return 0;
}

int	main(int c, char **v)
{
	struct s_so_long	game;
	struct s_image		imgtmp;

	char m[] = {'1', '1', '1', '1', '1', '1', '1',
                    '1', 'P', '1', '0', '0', '0', '1',
		    '1', '0', '0', 'C', '1', '0', '1',
                    '1', '1', '1', '1', '1', '1', '1',
	};
	get_args(c, v, &game);
	game.map.map = m;
	game.map.width = 7;
	game.map.height = 4;
        game.score = 0;
        game.keypresses = 0;
	mlxw_create_context(&game.mlx);
	mlxw_create_window(&game.mlx, s_window_create(CELL_SIZE * game.map.width,
			CELL_SIZE * game.map.height, "First window"));
        game.bg = s_image_create_xpm(game.mlx, "assets/background.xpm");
        game.collectible = s_image_create_xpm(game.mlx, "assets/food.xpm");
        game.wall = s_image_create_xpm(game.mlx, "assets/wall.xpm");
	imgtmp = s_image_create_xpm(game.mlx, "assets/plyerR0.xpm");
	game.player = *((struct s_player *)&imgtmp);
	game.player.x = 1;
	game.player.y = 1;
	s_hook_register(game.mlx, s_hook_create(E_DESTROY_NOTIFY, M_NONE, w_cl,
			&game.mlx));
	s_hook_register(game.mlx, s_hook_create(E_KEY_PRESSED, M_KEY_PRESSED,
			key_pressed, &game));
	render_map(&game);
	mlx_loop(game.mlx.ctx);
	so_long_unleak(game);
}
