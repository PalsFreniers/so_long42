/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:41:30 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/16 16:52:46 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxw_images.h>

void	mlxw_print_img(struct s_mlx mlx, struct s_image img)
{
	mlx_put_image_to_window(mlx.ctx, mlx.window, img.ctx.data, img.x, img.y);
}
