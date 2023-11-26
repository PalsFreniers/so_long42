/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <tdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:36:36 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/26 08:03:00 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/errors.h"
#include <stdlib.h>
#include <unistd.h>

void	handle_error_part2(int code)
{
	if (code == BORDER_ERROR)
		write(2, "[ERROR] -> error in map_borders\n", 32);
	else if (code == UNREACHABLE_EXIT)
		write(2, "[ERROR] -> unreachable exit\n", 28);
	else if (code == UNREACHABLE_COLLECTIBLE)
		write(2, "[ERROR] -> unreachable collectibles\n", 36);
	else
		write(2, "[ERROR] -> unhandled error\n", 27);
}

void	handle_error(int code)
{
	if (code == FILE_NOT_FOUND)
		write(2, "[ERROR] -> unable to find file\n", 31);
	else if (code == FILE_READ_ERROR)
		write(2, "[ERROR] -> unable to read file\n", 31);
	else if (code == TOO_MUCH_ARGUMENTS)
		write(2, "[ERROR] -> too much arguments\n", 30);
	else if (code == TOO_FEW_ARGUMENTS)
		write(2, "[ERROR] -> too few arguments\n", 29);
	else if (code == MALLOC_ERROR)
		write(2, "[ERROR] -> malloc did not work\n", 31);
	else if (code == BAD_MAP_EXTENTION)
		write(2, "[ERROR] -> file is not a .ber map\n", 34);
	else if (code == MAP_NOT_A_RECTANGLE)
		write(2, "[ERROR] -> map is not a rectangle\n", 34);
	else if (code == NO_COLLECTIBLES)
		write(2, "[ERROR] -> the map does not have collectibles\n", 46);
	else if (code == ILLEGAL_CHARACTER)
		write(2, "[ERROR] -> illegal character in map\n", 36);
	else if (code == BAD_PLAYER_NUMBER)
		write(2, "[ERROR] -> bad player number\n", 29);
	else if (code == BAD_EXIT_NUMBER)
		write(2, "[ERROR] -> bad exit number\n", 27);
	else
		handle_error_part2(code);
	exit(code);
}
