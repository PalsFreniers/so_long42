/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_hooks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:40:13 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/12 08:29:57 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXW_HOOKS_H
# define MLXW_HOOKS_H

# include "mlx.h"
# include "mlxw_ctx.h"

enum			e_event
{
	E_KEY_PRESSED = 2,
	E_KEY_RELEASED = 3,
	E_BUTTON_PRESSED = 4,
	E_BUTTON_RELEASED = 5,
	E_MOTION_NOTIFY = 6,
	E_ENTERN_NOTIFY = 7,
	E_LEAVE_NOTIFY = 8,
	E_FOCU_IN = 9,
	E_FOCUS_OUT = 10,
	E_KEYMAP_NOTIFY = 11,
	E_EXPOSE = 12,
	E_GRAPHICS_EXPOSE = 13,
	E_NO_EXPOSE = 14,
	E_VISIBILITY_NOTIFY = 15,
	E_CREATE_NOTIFY = 16,
	E_DESTROY_NOTIFY = 17,
	E_UNMAP_NOTIFY = 18,
	E_MAP_NOTIFY = 19,
	E_MAP_REQUEST = 20,
	E_REPARENT_NOTIFY = 21,
	E_CONFIGURE_NOTIFY = 22,
	E_CONFIGURE_REQUEST = 23,
	E_GRAVITY_NOTIFY = 24,
	E_RESIZE_REQUEST = 25,
	E_CIRCULATE_NOTIFY = 26,
	E_CIRCULATE_REQUEST = 27,
	E_PROPERTY_NOTIFY = 28,
	E_SELECTION_CLEAR = 29,
	E_SELECTION_REQUEST = 30,
	E_SELECTION_NOTIFY = 31,
	E_COLORMAP_NOTIFY = 32,
	E_CLIENT_MESSAGE = 33,
	E_MAPPING_NOTIFY = 34,
	E_GENERIC_EVENT = 35,
	E_LAST = 36,
};

enum			e_mask
{
	M_NONE = 0L,
	M_KEY_PRESSED = (1L << 0),
	M_KEY_RELEASED = (1L << 1),
	M_BUTTON_PRESSED = (1L << 2),
	M_BUTTON_RELEASED = (1L << 3),
	M_ENTER_WINDOW = (1L << 4),
	M_LEAVE_WINDOW = (1L << 5),
	M_POINTER_MOTION = (1L << 6),
	M_POINTER_MOTIONHINT = (1L << 7),
	M_BUTTON1_MOTION = (1L << 8),
	M_BUTTON2_MOTION = (1L << 9),
	M_BUTTON3_MOTION = (1L << 10),
	M_BUTTON4_MOTION = (1L << 11),
	M_BUTTON5_MOTION = (1L << 12),
	M_BUTTON_MOTION = (1L << 13),
	M_KEYMAP_STATE = (1L << 14),
	M_EXPOSURE = (1L << 15),
	M_VISIBILITY_CHANGE = (1L << 16),
	M_STRUCTURE_NOTIFY = (1L << 17),
	M_RESIZE_REDIRECT = (1L << 18),
	M_SUBSTRUCTURE_NOTIFY = (1L << 19),
	M_SUBSTRUCTURE_REDIRECT = (1L << 20),
	M_FOCUS_CHANGE = (1L << 21),
	M_PROPERTY_CHANGE = (1L << 22),
	M_COLORMAP_CHANGE = (1L << 23),
	M_OWNER_GRAB_BUTTON = (1L << 24),
};

enum			e_mouse_button
{
	M_LEFT = 1,
	M_RIGHT = 2,
	M_MIDDLE = 3,
	M_SCROLL_UP = 4,
	M_SCROLL_DOWN = 5,
};

enum			e_keycode
{
	K_LEFT = 65361,
	K_UP = 65362,
	K_RIGHT = 65363,
	K_DOWN = 65364,
};

struct			s_hook
{
	int			event;
	int			mask;
	int			(*hook)();
	void		*params;
};

struct s_hook	s_hook_create(int event, int mask, int (*f)(), void *param);
void			s_hook_register(struct s_mlx mlx, struct s_hook hook);

#endif // MLXW_HOOKS_H
