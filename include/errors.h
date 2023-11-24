/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <tdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:14:33 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/22 18:25:59 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

enum	e_error_code
{
	FILE_NOT_FOUND = 1,
	FILE_READ_ERROR = 2,
	TOO_MUCH_ARGUMENTS = 3,
	TOO_FEW_ARGUMENTS = 4,
	MALLOC_ERROR = 5,
	BAD_MAP_EXTENTION = 6,
	MAP_NOT_A_RECTANGLE = 7,
	NO_COLLECTIBLES = 8,
	ILLEGAL_CHARACTER = 9,
	BAD_PLAYER_NUMBER = 10,
	BAD_EXIT_NUMBER = 11,
	BORDER_ERROR = 12,
	UNREACHABLE_EXIT = 13,
	UNREACHABLE_COLLECTIBLE = 14,
};

void	handle_error(int code);

#endif // ERRORS_H
