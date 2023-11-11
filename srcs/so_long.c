/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 05:13:41 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/11 06:19:44 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.c>
#include "../include/mlx.h"
#include "../include/mlxw.h"

void	my_mlx_pixel_put(struct s_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->width + x * (data->BPP / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
        struct s_mlx mlx;
        struct s_image img;

        mlxw_create_context(&mlx);
        mlxw_create_window(&mlx, s_window_create(600, 400, "First window"));

        img.data = mlx_new_image(mlx.ctx, 600, 400);
        img.address = mlx_get_data_addr(img.data, &img.BPP, &img.width, &img.endian);

        my_mlx_pixel_put(&img, 20, 20, 0xFFFFFFFF);
        mlx_put_image_to_window(mlx.ctx, mlx.window, img.data, 0, 0);

	mlx_loop(mlx.ctx);
}
