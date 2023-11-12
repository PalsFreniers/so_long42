#include "../include/file_utils.h"

static void	slurp_read_error(char *file, int fd)
{
	free(file);
	close(fd);
	handle_error(FILE_READ_ERROR);
}

char	*slurp(char *path)
{
	int		ret;
	char	*file;
	char	*tmp;
	char	buf[SLURP_BUF_SIZE];
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_error(FILE_NOT_FOUND);
	file = ft_calloc(1, 1);
	if (file == NULL)
		handle_error(MALLOC_ERROR);
	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buf, SLURP_BUF_SIZE - 1);
		if (ret == -1)
			slurp_read_error(file, fd);
		tmp = file;
		file = ft_strjoin(file, buf);
		free(tmp);
		if (file == NULL)
			handle_error(MALLOC_ERROR);
	}
	return (file);
}

void handle_error(int code) {
        if(code == FILE_NOT_FOUND)
                write(2, "[ERROR] -> unable to read file\n", 31);
        else
                write(2, "[ERROR] -> unhandled error\n", 27);
        exit(code);
}
