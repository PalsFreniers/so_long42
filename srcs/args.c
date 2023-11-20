/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:21:43 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/20 11:21:44 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*get_file(int c, char **v)
{
	if (c < 2)
		handle_error(TOO_FEW_ARGUMENTS);
	if (c > 2)
		handle_error(TOO_MUCH_ARGUMENTS);
	if (!ft_strsufix(v[1], ".ber"))
		handle_error(BAD_MAP_EXTENTION);
	return (v[1]);
}
