/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <tdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:47:39 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/22 18:26:04 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*cache_at(char *cache, int x, int y, int width)
{
	return (cache + (x + y * width));
}

void	ff_r(struct s_so_long *game, struct s_flood_fill *ff, struct s_v2 pos)
{
	if (*cache_at(ff->cache, pos.x, pos.y, game->map.width) != 0)
		return ;
	if (*map_at(game, pos.x, pos.y) == '1')
	{
		*cache_at(ff->cache, pos.x, pos.y, game->map.width) = -1;
		return ;
	}
	if (*map_at(game, pos.x, pos.y) == 'E')
	{
		ff->exit = 1;
		*cache_at(ff->cache, pos.x, pos.y, game->map.width) = -1;
		return ;
	}
	if (*map_at(game, pos.x, pos.y) == 'C')
	{
		ff->score++;
		*cache_at(ff->cache, pos.x, pos.y, game->map.width) = 1;
	}
	else if (*map_at(game, pos.x, pos.y) == 'P' || *map_at(game, pos.x,
			pos.y) == '0')
		*cache_at(ff->cache, pos.x, pos.y, game->map.width) = 1;
	ff_r(game, ff, (struct s_v2){pos.x + 1, pos.y});
	ff_r(game, ff, (struct s_v2){pos.x - 1, pos.y});
	ff_r(game, ff, (struct s_v2){pos.x, pos.y + 1});
	ff_r(game, ff, (struct s_v2){pos.x, pos.y - 1});
}

void	ff_error(struct s_so_long *game, struct s_flood_fill ff, int code)
{
	if (ff.cache)
		free(ff.cache);
	map_error(game, code);
}

void	ff_check(struct s_so_long *game)
{
	struct s_flood_fill	ff;

	ff.cache = ft_calloc(game->map.width * game->map.height + 1, sizeof(char));
	if (!ff.cache)
		map_error(game, MALLOC_ERROR);
	ff.score = 0;
	ff.exit = 0;
	ff_r(game, &ff, (struct s_v2){game->player.x, game->player.y});
	if (ff.exit != 1)
		ff_error(game, ff, UNREACHABLE_EXIT);
	if (ff.score != game->map.col_nbr)
		ff_error(game, ff, UNREACHABLE_COLLECTIBLE);
	free(ff.cache);
}
