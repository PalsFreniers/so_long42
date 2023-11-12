/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_struct_fini.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:05:42 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/12 09:12:17 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxw_ctx.h>
#include <mlxw_images.h>
#include <malloc.h>

void	s_image_destroy(struct s_mlx mlx, struct s_image img)
{
	mlx_destroy_image(mlx.ctx, img.ctx.data);
}

void	mlxw_destroy_window(struct s_mlx mlx)
{
	mlx_destroy_window(mlx.ctx, mlx.window);
}

void	mlxw_destroy_context(struct s_mlx mlx)
{
	mlx_destroy_display(mlx.ctx);
	free(mlx.ctx);
}
