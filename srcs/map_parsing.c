/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <tdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:08:37 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/15 21:13:41 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <malloc.h>

void	map_parse(struct s_so_long *game, char *filePath)
{
	char	*file;
	char	*f;
	size_t	size;
	size_t	lines;

	file = slurp(filePath);
	f = ft_strtrim(file, "\n");
	free(file);
	ft_count(f, '\n', &size, &lines);
	game->map.map = (char *)ft_calloc(size + 1, sizeof(char));
	game->map.width = ft_strlenc(f, '\n');
	game->map.height = lines;
	if (size / lines != game->map.width)
		handle_error(MAP_NOT_A_RECTANGLE);
}
