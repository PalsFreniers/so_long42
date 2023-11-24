/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <tdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:08:37 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/22 16:52:31 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <malloc.h>

int	check_map_impl(int *nbcol, int *player, int *exit, struct s_so_long *game)
{
	struct s_v2	pos;
	char		c;

	pos.y = 1;
	while (pos.y < game->map.height - 1)
	{
		pos.x = 1;
		while (pos.x < game->map.width - 1)
		{
			c = *map_at(game, pos.x, pos.y);
			if (c == MAP_COLLECTIBLE)
				(*nbcol)++;
			else if (c == MAP_PLAYER)
				player_add(game, player, pos);
			else if (c == MAP_EXIT)
				exit_add(game, exit, pos);
			else if (c != MAP_WALL && c != MAP_EMPTY)
				return (-1);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

void	map_error(struct s_so_long *game, int code)
{
	if (game->map.map)
		free(game->map.map);
	handle_error(code);
}

void	map_copy(struct s_so_long *game, char *f)
{
	size_t	t;

	t = 0;
	while (*f)
	{
		if (*f != '\n')
			game->map.map[t++] = *f;
		f++;
	}
}

int	check_map_init(char *f, struct s_so_long *game)
{
	int	nbcol;
	int	player;
	int	exit;

	nbcol = 0;
	player = 0;
	exit = 0;
	game->map.map = (char *)ft_calloc(game->map.width * game->map.height + 1,
			sizeof(char));
	if (!game->map.map)
		handle_error(MALLOC_ERROR);
	map_copy(game, f);
	free(f);
	check_borders(game);
	if (check_map_impl(&nbcol, &player, &exit, game) == -1)
		map_error(game, ILLEGAL_CHARACTER);
	else if (nbcol == 0)
		map_error(game, NO_COLLECTIBLES);
	else if (player != 1)
		map_error(game, BAD_PLAYER_NUMBER);
	else if (exit != 1)
		map_error(game, BAD_EXIT_NUMBER);
	return (nbcol);
}

void	map_parse(struct s_so_long *game, char *filePath)
{
	char	*file;
	char	*f;
	size_t	size;
	size_t	lines;

	file = slurp(filePath);
	if (!file)
		handle_error(MALLOC_ERROR);
	f = ft_strtrim(file, "\n");
	if (!f)
		handle_error(MALLOC_ERROR);
	free(file);
	ft_count(f, '\n', &lines, &size);
	game->map.width = ft_strlenc(f, '\n');
	game->map.height = lines + 1;
	if (size != game->map.height * game->map.width)
	{
		free(f);
		handle_error(MAP_NOT_A_RECTANGLE);
	}
	game->map.col_nbr = check_map_init(f, game);
	ft_srand(game->map.width * size ^ game->map.height);
}
