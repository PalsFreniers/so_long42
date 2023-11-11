#ifndef MLXW_H
# define MLXW_H

#include "mlx.h"

struct					s_mlx
{
	void				*ctx;
	void				*window;
};

struct					s_img_dat
{
	void				*data;
	char				*address;
	int					bpp;
	int					width;
	int					endian;
};

struct					s_image
{
	struct s_img_dat	ctx;
	int					x;
	int					y;
};

struct					s_window
{
	int					width;
	int					height;
	char				*title;
};

// create function for structs
struct s_window s_window_create(int x, int y, char *title);

void					mlxw_create_context(struct s_mlx *mlx);
void					mlxw_create_window(struct s_mlx *mlx,
							struct s_window win);
void					mlxw_print_img(struct s_mlx mlx, struct s_image image);

#endif // MLXW_H
