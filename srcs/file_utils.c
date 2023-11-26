/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:21:47 by tdelage           #+#    #+#             */
/*   Updated: 2023/11/26 08:03:06 by tdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/errors.h"
#include "../include/file_utils.h"

static void	slurp_read_error(char *file, int fd)
{
	if (fd >= 0)
		return ;
	free(file);
	close(fd);
	handle_error(FILE_READ_ERROR);
}

static void	slurp_malloc_error(char *file)
{
	if (file == NULL)
		handle_error(MALLOC_ERROR);
}

char	*join_and_free(char *file, char *buf)
{
	char	*tmp;

	tmp = file;
	file = ft_strjoin(file, buf);
	free(tmp);
	return (file);
}

char	*slurp(char *path)
{
	int		ret;
	char	*file;
	char	buf[SLURP_BUF_SIZE + 1];
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_error(FILE_NOT_FOUND);
	file = ft_calloc(1, 1);
	slurp_malloc_error(file);
	ret = 1;
	ft_memset(buf, 0, SLURP_BUF_SIZE);
	while (ret != 0)
	{
		ret = read(fd, buf, SLURP_BUF_SIZE - 1);
		buf[ret] = 0;
		if (ret == 0)
			return (file);
		slurp_read_error(file, fd);
		file = join_and_free(file, buf);
		slurp_malloc_error(file);
	}
	return (file);
}
