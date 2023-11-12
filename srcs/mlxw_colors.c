/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:04:34 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/12 01:35:13 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxw_colors.h>

struct s_color	mlxw_argb_to_color(int color)
{
	return ((struct s_color){
		.r = color >> (2 * 8) & 0xFF,
		.g = color >> (1 * 8) & 0xFF,
		.b = color >> (0 * 8) & 0xFF,
		.a = color >> (3 * 8) & 0xFF,
	});
}

int	mlxw_color_to_argb(struct s_color color)
{
	return (color.a << (3 * 8) | color.r << (2 * 8) | color.g << (1
			* 8) | color.b << (0 * 8));
}

int	mlxw_rgba_to_argb(int rgba)
{
	return (rgba >> 8 | rgba << 24);
}
