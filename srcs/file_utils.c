#include "../include/errors.h"
#include "../include/file_utils.h"

static void	slurp_read_error(char *file, int fd)
{
	free(file);
	close(fd);
	handle_error(FILE_READ_ERROR);
}

static void	slurp_malloc_error(char *file)
{
	if (file == NULL)
		handle_error(MALLOC_ERROR);
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
	slurp_malloc_error(file);
	ret = 1;
	ft_memset(buf, 0, SLURP_BUF_SIZE);
	while (ret != 0)
	{
		buf[0] = 0;
		ret = read(fd, buf, SLURP_BUF_SIZE - 1);
		if (ret == -1)
			slurp_read_error(file, fd);
		tmp = file;
		file = ft_strjoin(file, buf);
		free(tmp);
		slurp_malloc_error(file);
	}
	return (file);
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
		write(2, "[ERROR] -> unhandled error\n", 27);
	exit(code);
}
