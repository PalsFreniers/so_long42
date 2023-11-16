NAME = so_long

SRCS =    srcs/so_long.c    	  \
	  srcs/so_long_p2.c	  \
	  srcs/render_map.c       \
	  srcs/file_utils.c       \
	  srcs/mlxw_ctx.c 	  \
	  srcs/mlxw_hooks.c       \
	  srcs/mlxw_colors.c      \
	  srcs/mlxw_images.c      \
	  srcs/mlxw_struct_init.c \
	  srcs/mlxw_struct_fini.c

HEADERS = include/mlx.h         \
	  include/mlx_int.h     \
	  include/mlxw.h        \
	  include/mlxw_ctx.h    \
	  include/mlxw_hooks.h  \
	  include/mlxw_colors.h \
	  include/mlxw_images.h

FT_HEADER = include/libft.h

OBJS = $(SRCS:.c=.o)

LIBS = -lft -lmlx -lXext -lX11 -lm -lz
LIBPATH = -Llib
INCLUDEPATH = -I./include
CC = clang-15
CFLAGS = -g -ggdb -gdwarf-2 # -Wall -Wextra -Werror
LD = clang-15
LDFLAGS = $(LIBPATH) $(LIBS)

all: $(NAME)

$(NAME): $(FT_HEADER) $(OBJS)
	$(LD) -o $(NAME) $(OBJS) $(LDFLAGS)

$(FT_HEADER):
	make -j 3 -C lib/libft
	cp lib/libft/libft.a lib
	cp lib/libft/libft.h include

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDEPATH)

clean:
	make clean -C lib/libft
	rm -rf $(FT_HEADER)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C lib/libft
	rm -rf lib/libft.a
	rm -rf $(NAME)

re: fclean all

run: re
	./so_long

.PHONY: all clean fclean re
