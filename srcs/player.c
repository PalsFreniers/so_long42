/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <tdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 08:38:06 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/26 08:03:55 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	player_check_enemy(struct s_so_long *game, struct s_v2 post,
		struct s_v2 pos)
{
	if (*map_at(game, post.x + pos.x, post.y + pos.y) == MAP_ENEMY)
	{
		game->flags |= FLAG_KILLED;
		return (1);
	}
	return (0);
}

void	player_move(struct s_so_long *game, int x, int y)
{
	size_t	xt;
	size_t	yt;

	xt = game->player.x;
	yt = game->player.y;
	if (xt + x < 1 || xt + x >= game->map.width - 1 || yt + y < 1 || yt
		+ y >= game->map.height - 1)
		return ;
	if (*map_at(game, xt + x, yt + y) == MAP_WALL)
		return ;
	if (*map_at(game, xt + x, yt + y) == MAP_EXIT)
	{
		if (game->can_exit)
			game->flags |= FLAG_END_OF_GAME;
		return ;
	}
	if (*map_at(game, xt + x, yt + y) == MAP_COLLECTIBLE)
	{
		game->score++;
		refresh_score(game);
	}
	if (player_check_enemy(game, (struct s_v2){xt, yt}, (struct s_v2){x, y}))
		return ;
	refresh_player_cells(game, (struct s_v2){x, y}, (struct s_v2){xt, yt});
	refresh_numbers(game);
}
