/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 05:13:41 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/24 14:07:25 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/file_utils.h"
#include "../include/so_long.h"

char	*map_at(struct s_so_long *game, int x, int y)
{
	struct s_map	map;
	int				width;

	map = game->map;
	width = map.width;
	return (&(map.map[x + y * width]));
}

int	key_pressed(int code, struct s_so_long *game)
{
	if (code == K_ESCAPE)
		mlx_loop_end(game->mlx.ctx);
	if (code == K_P && !(game->flags & FLAG_WON))
		game->flags ^= FLAG_PAUSE;
	if (game->flags & FLAG_PAUSE)
		return (1);
	if (code == K_UP || code == K_W)
		player_move(game, 0, -1);
	if (code == K_DOWN || code == K_S)
		player_move(game, 0, 1);
	if (code == K_LEFT || code == K_A)
	{
		player_move(game, -1, 0);
		game->player.left = 0;
	}
	if (code == K_RIGHT || code == K_D)
	{
		player_move(game, 1, 0);
		game->player.left = 1;
	}
	return (1);
}

void	f_loop_enemy(struct s_so_long *game)
{
	int	i;

	if (!(game->flags & FLAG_PAUSE) && game->ticks % 6000 == 0)
	{
		game->enemy.current_frame++;
		if (game->enemy.current_frame == 6)
			game->enemy.current_frame = 0;
		game->enemy.ctx = game->enemy.frames[game->enemy.current_frame].ctx;
		i = 0;
		while (i < game->enemy.nb)
		{
			map_render(game, game->enemy.poss[i].x, game->enemy.poss[i].y);
			i++;
		}
	}
	if (game->flags & FLAG_KILLED)
	{
		game->flags &= ~FLAG_KILLED;
		game->flags |= FLAG_PAUSE;
                game->flags |= FLAG_WON;
		mlxw_print_img(game->mlx, game->killed_screen);
	}
}

int	f_loop(struct s_so_long *game)
{
	if (!game->can_exit && game->score == game->map.col_nbr)
	{
		game->exit.current = game->exit.frames[1];
		map_render(game, game->exit.pos.x, game->exit.pos.y);
		game->can_exit = 1;
	}
	if (game->flags & FLAG_END_OF_GAME)
	{
		game->flags &= ~FLAG_END_OF_GAME;
		game->flags |= FLAG_PAUSE;
		game->flags |= FLAG_WON;
		mlxw_print_img(game->mlx, game->end_screen);
	}
	game->ticks++;
	if (!(game->flags & FLAG_PAUSE) && game->ticks % 8500 == 0)
	{
		game->player.current_frame++;
		if (game->player.current_frame == 3)
			game->player.current_frame = 0;
		game->player.ctx = game->player.frames[game->player.current_frame + (3
			* game->player.left)].ctx;
		map_render(game, game->player.x, game->player.y);
	}
	f_loop_enemy(game);
	return (1);
}
