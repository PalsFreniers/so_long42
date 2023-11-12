/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_colors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 01:37:46 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/12 01:39:48 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXW_COLORS_H
# define MLXW_COLORS_H

# include "mlx.h"
# include "mlxw_ctx.h"

# define MLXWC_RED 0xFFFF0000
# define MLXWC_GREEN 0xFF00FF00
# define MLXWC_BLUE 0xFF0000FF
# define MLXWC_WHITE 0xFFFFFFFF
# define MLXWC_BLACK 0x00000000
# define MLXWC_GREY 0x88888888
# define MLXWC_DARK_GREY 0x22222222

struct			s_color
{
	char		r;
	char		g;
	char		b;
	char		a;
};

struct s_color	mlxw_argb_to_color(int color);
int				mlxw_color_to_argb(struct s_color col);
int				mlxw_rgba_to_argb(int rgba);

#endif // MLXW_COLORS_H
