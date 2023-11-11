#include "../include/mlxw.h"

struct s_window	s_window_create(int width, int height, char *title)
{
	return ((struct s_window){
		.width = width,
		.height = height,
		.title = title,
	});
}
