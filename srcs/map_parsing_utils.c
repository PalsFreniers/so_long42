/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:08:19 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/20 11:11:13 by tdelage          ###   ########.fr       */
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
