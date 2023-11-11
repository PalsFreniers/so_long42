NAME = so_long

SRCS =    srcs/so_long.c    		\
	  srcs/mlxw_part1.c 		\
	  srcs/mlxw_struct_init_part1.c 

HEADERS = include/mlx.h     \
	  include/mlx_int.h \
	  include/mlxw.h

OBJS = $(SRCS:.c=.o)

LIBS = -lmlx -lXext -lX11 -lm -lz
LIBPATH = -Llib
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
LD = cc
LDFLAGS = $(LIBPATH) $(LIBS)

all: $(NAME)

$(NAME): $(OBJS)
	$(LD) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o: %.c $(HEADERS)
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
