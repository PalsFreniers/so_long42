#include "../include/so_long.h"
#include <printf.h>

void	map_render(struct s_so_long *game, int x, int y)
{
	int				map_w;
	char			*map;
	struct s_image	img;

	map_w = game->map.width;
	map = game->map.map;
	if (map[x + y * map_w] == MAP_WALL)
		img.ctx = game->wall.ctx;
	else if (map[x + y * map_w] == MAP_COLLECTIBLE)
		img.ctx = game->collectible.ctx;
	else if (map[x + y * map_w] == MAP_EXIT)
		img.ctx = game->exit.ctx;
	else if (map[x + y * map_w] == MAP_EMPTY)
		img.ctx = game->bg.ctx;
	else if (map[x + y * map_w] == MAP_PLAYER)
		img.ctx = game->player.ctx;
	else
		return ;
	img.x = x * CELL_SIZE;
	img.y = y * CELL_SIZE;
	mlxw_print_img(game->mlx, img);
}

void	render_map(struct s_so_long *game)
{
	int	x;
	int	y;

	y = 0;
	(void)game;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			map_render(game, x, y);
			x++;
		}
		y++;
	}
}
