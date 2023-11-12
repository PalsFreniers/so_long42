#include "../include/so_long.h"

void	render_map(struct s_so_long *game) {
        int x;
        int y;

        y = 0;
        while(y < MAP_HEIGHT) {
                x = 0;
                while(x < MAP_WIDTH) {
                        game->bg.x = x * CELL_SIZE;
                        game->bg.y = y * CELL_SIZE;
                        mlxw_print_img(game->mlx, game->bg);
                        x++;
                }
                y++;
        }
}
