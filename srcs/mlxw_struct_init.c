/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_struct_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 01:26:13 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/12 09:06:09 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxw_ctx.h>
#include <mlxw_hooks.h>
#include <mlxw_images.h>

struct s_window	s_window_create(int width, int height, char *title)
{
	return ((struct s_window){
		.width = width,
		.height = height,
		.title = title,
	});
}

struct s_image	s_image_create_empty(struct s_mlx mlx, int width, int height)
{
	struct s_img_dat	ctx;

	ctx.data = mlx_new_image(mlx.ctx, width, height);
	ctx.address = mlx_get_data_addr(ctx.data, &ctx.bpp, &ctx.llenght,
			&ctx.endian);
	return ((struct s_image){
		.ctx = ctx,
		.x = 0,
		.y = 0,
		.w = width,
		.h = height,
	});
}

struct s_image	s_image_create_xpm(struct s_mlx mlx, const char *path)
{
	int					w;
	int					h;
	struct s_img_dat	ctx;

	ctx.data = mlx_xpm_file_to_image(mlx.ctx, (char *)path, &w, &h);
	ctx.address = mlx_get_data_addr(ctx.data, &ctx.bpp, &ctx.llenght,
			&ctx.endian);
	return ((struct s_image){
		.ctx = ctx,
		.x = 0,
		.y = 0,
		.w = w,
		.h = h,
	});
}

struct s_hook	s_hook_create(int event, int mask, int (*f)(), void *param)
{
	return ((struct s_hook){
		.event = event,
		.mask = mask,
		.hook = f,
		.params = param,
	});
}
