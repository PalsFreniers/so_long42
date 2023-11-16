/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <tdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:14:33 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/15 21:15:17 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
#define ERRORS_H

enum					e_error_code
{
	FILE_NOT_FOUND = 1,
	FILE_READ_ERROR = 2,
	TOO_MUCH_ARGUMENTS = 3,
	TOO_FEW_ARGUMENTS = 4,
	MALLOC_ERROR = 5,
	BAD_MAP_EXTENTION = 6,
        MAP_NOT_A_RECTANGLE = 7,
};

void					handle_error(int code);

#endif // ERRORS_H
