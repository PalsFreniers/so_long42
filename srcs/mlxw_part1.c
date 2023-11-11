#include "../include/mlxw.h"

void	mlxw_create_context(struct s_mlx *mlx)
{
	mlx->ctx = mlx_init();
}

void	mlxw_create_window(struct s_mlx *mlx, struct s_window win)
{
	mlx->window = mlx_new_window(mlx->ctx, win.width, win.height, win.title);
}

void	mlxw_print_img(struct s_mlx mlx, struct s_image img)
{
	mlx_put_image_to_window(mlx.ctx, mlx.window, img.ctx.data, img.x, img.y);
}
