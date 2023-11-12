/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:56:43 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/12 14:48:44 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlxw.h"
#include "file_utils.h"

# define MAP_WIDTH 15
# define MAP_HEIGHT 10
# define CELL_SIZE 64

struct				s_so_long
{
	struct s_mlx	mlx;
	struct s_image	bg;
	struct s_image	player;
        char *map;
};

void	render_map(struct s_so_long *game);
void get_args(int c, char **v, struct s_so_long *game);

#endif // SO_LONG_H
