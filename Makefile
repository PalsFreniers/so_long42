NAME = so_long

SRCS =    srcs/main.c              \
	  srcs/sl_init.c           \
	  srcs/sl_fini.c           \
	  srcs/so_long.c    	   \
	  srcs/player.c    	   \
	  srcs/args.c              \
	  srcs/render_map.c        \
	  srcs/errors.c            \
	  srcs/map_parsing.c       \
	  srcs/map_parsing_utils.c \
	  srcs/flood_fill.c        \
	  srcs/file_utils.c        \
	  srcs/mlxw_ctx.c 	   \
	  srcs/mlxw_hooks.c        \
	  srcs/mlxw_colors.c       \
	  srcs/mlxw_images.c       \
	  srcs/mlxw_struct_init.c  \
	  srcs/mlxw_struct_fini.c

HEADERS = include/mlx.h         \
	  include/mlx_int.h     \
	  include/mlxw.h        \
	  include/mlxw_ctx.h    \
	  include/mlxw_hooks.h  \
	  include/mlxw_colors.h \
	  include/mlxw_images.h \
	  include/libft.h       \
	  include/so_long.h     \
	  include/errors.h      \
	  include/file_utils.h  \
	  include/map_parsing.h 

LIBFT = lib/libft.a

OBJS = $(SRCS:.c=.o)

LIBS = -lft -lmlx -lXext -lX11 -lm -lz
LIBPATH = -Llib
INCLUDEPATH = -I./include
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror $(INCLUDEPATH)
LD = gcc
LDFLAGS =$(LIBPATH) $(LIBS)
LIBMLX = lib/libmlx.a

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	@$(LD) -o $(NAME) $(OBJS) $(LDFLAGS)
	@echo "so_long compilation finished !!!"

all: $(NAME)

$(LIBFT):
	@make --no-print-directory -j 4 -C lib/libft
	@cp lib/libft/libft.a lib
	@cp lib/libft/libft.h include

$(LIBMLX):
	@make --no-print-directory -j 4 -C lib/libmlx
	@cp lib/libmlx/libmlx.a lib
	@cp lib/libmlx/mlx.h lib/libmlx/mlx_int.h include

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@make clean --no-print-directory -C lib/libft
	@make clean --no-print-directory -C lib/libmlx
	@rm -rf include/libft.h
	@rm -rf include/mlx.h include/mlx_int.h 
	@rm -rf $(OBJS)
	@echo "cleaned"

fclean: clean
	@make fclean --no-print-directory -C lib/libft
	@make fclean --no-print-directory -C lib/libmlx
	@rm -rf lib/libft.a
	@rm -rf lib/libmlx.a
	@rm -rf $(NAME)
	@echo "fcleaned"

re: fclean all

run: re
	./$(NAME) maps/test.ber

rdebug: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) maps/test2.ber

.PHONY: all clean fclean re
