/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:08:19 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/26 08:03:46 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_add(struct s_so_long *game, int *player, struct s_v2 pos)
{
	game->player.x = pos.x;
	game->player.y = pos.y;
	(*player)++;
}

void	exit_add(struct s_so_long *game, int *exit, struct s_v2 pos)
{
	game->exit.pos = pos;
	(*exit)++;
}

void	check_borders_part1(struct s_so_long *game)
{
	struct s_v2	pos;

	pos.x = 0;
	pos.y = 0;
	while (pos.y < game->map.height)
	{
		if (*map_at(game, pos.x, pos.y) != '1')
			map_error(game, BORDER_ERROR);
		pos.y++;
	}
	pos.y--;
	while (pos.x < game->map.width)
	{
		if (*map_at(game, pos.x, pos.y) != '1')
			map_error(game, BORDER_ERROR);
		pos.x++;
	}
}

void	check_borders(struct s_so_long *game)
{
	struct s_v2	pos;

	check_borders_part1(game);
	pos.x = 0;
	pos.y = 0;
	while (pos.x < game->map.width)
	{
		if (*map_at(game, pos.x, pos.y) != '1')
			map_error(game, BORDER_ERROR);
		pos.x++;
	}
	pos.x--;
	while (pos.y < game->map.height)
	{
		if (*map_at(game, pos.x, pos.y) != '1')
			map_error(game, BORDER_ERROR);
		pos.y++;
	}
}
