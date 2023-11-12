/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_ctx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:41:26 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/12 09:12:46 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxw_ctx.h>

void	mlxw_create_context(struct s_mlx *mlx)
{
	mlx->ctx = mlx_init();
}

void	mlxw_create_window(struct s_mlx *mlx, struct s_window win)
{
	mlx->window = mlx_new_window(mlx->ctx, win.width, win.height, win.title);
}

void	mlxw_clear(struct s_mlx mlx)
{
	mlx_clear_window(mlx.ctx, mlx.window);
}
