/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_ctx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 01:37:42 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/20 11:26:12 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXW_CTX_H
# define MLXW_CTX_H

# include "mlx.h"
# include <stddef.h>

struct			s_mlx
{
	void		*ctx;
	void		*window;
};

struct			s_window
{
	int			width;
	int			height;
	char		*title;
};

// create function for structs
struct s_window	s_window_create(int x, int y, char *title);
void			mlxw_create_context(struct s_mlx *mlx);
void			mlxw_destroy_context(struct s_mlx mlx);
void			mlxw_create_window(struct s_mlx *mlx, struct s_window win);
void			mlxw_destroy_window(struct s_mlx mlx);
void			mlxw_clear(struct s_mlx mlx);

#endif // MLXW_CTX_H
