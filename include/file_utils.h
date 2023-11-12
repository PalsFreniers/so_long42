/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:59:25 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/12 15:01:08 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_UTILS_H
# define FILE_UTILS_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define SLURP_BUF_SIZE 1024

enum	e_error_code
{
	FILE_NOT_FOUND = 1,
	FILE_READ_ERROR = 2,
	TOO_MUCH_ARGUMENTS = 3,
	TOO_FEW_ARGUMENTS = 4,
	MALLOC_ERROR = 5,
	BAD_MAP_EXTENTION = 6,
};

char	*slurp(char *path);
void	handle_error(int code);

#endif // FILE_UTILS_H
