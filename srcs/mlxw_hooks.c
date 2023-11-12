/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:35:13 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/12 04:18:02 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <mlxw_hooks.h>

void	s_hook_register(struct s_mlx mlx, struct s_hook hook)
{
	if (!mlx.window)
		return ;
	mlx_hook(mlx.window, hook.event, hook.mask, hook.hook, hook.params);
}
