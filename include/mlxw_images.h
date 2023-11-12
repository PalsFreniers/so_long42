/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_images.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 01:37:31 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/12 09:13:16 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXW_IMAGES_H
# define MLXW_IMAGES_H

# include "mlx.h"
# include "mlxw_ctx.h"

struct					s_img_dat
{
	void				*data;
	char				*address;
	int					bpp;
	int					llenght;
	int					endian;
};

struct					s_image
{
	struct s_img_dat	ctx;
	int					x;
	int					y;
	int					w;
	int					h;
};

struct s_image			s_image_create_empty(struct s_mlx mlx, int xidth,
							int height);
struct s_image			s_image_create_xpm(struct s_mlx mlx, const char *path);
void					s_image_destroy(struct s_mlx mlx, struct s_image img);
void					mlxw_print_img(struct s_mlx mlx, struct s_image image);

#endif // MLXW_IMAGES_H
