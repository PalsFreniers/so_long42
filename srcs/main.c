/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:35:20 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/24 08:23:46 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int c, char **v)
{
	struct s_so_long	game;

	map_parse(&game, get_file(c, v));
	flood_fill_check(&game);
	init_game(&game);
        *map_at(&game, 2, 2) = MAP_ENEMY;
        struct s_v2 pos = {2, 2};
        game.enemy.poss = &pos;
        game.enemy.nb = 1;
	s_hook_register(game.mlx, s_hook_create(E_DESTROY_NOTIFY, M_NONE,
			mlx_loop_end, game.mlx.ctx));
	s_hook_register(game.mlx, s_hook_create(E_KEY_PRESSED, M_KEY_PRESSED,
			key_pressed, &game));
	render_map(&game);
	refresh_numbers(&game);
	refresh_score(&game);
	mlx_loop_hook(game.mlx.ctx, f_loop, &game);
	mlx_loop(game.mlx.ctx);
	so_long_unleak(game);
}
