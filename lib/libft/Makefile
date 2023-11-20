CC = cc
LD = ar
NAME = libft.a
SRCS = ft_rand.c ft_strsufix.c ft_count.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_strtrim.c ft_substr.c ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_strjoin.c ft_split.c ft_calloc.c ft_strdup.c ft_atoi.c ft_strnstr.c ft_memcmp.c ft_memchr.c ft_strncmp.c ft_strrchr.c ft_strchr.c ft_tolower.c ft_toupper.c ft_strlcat.c ft_strlcpy.c ft_memmove.c ft_memcpy.c ft_bzero.c ft_memset.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
HEADER = "libft.h"
OBJS = $(SRCS:.c=.o)
CFLAGS = -fPIE -Wall -Wextra -Werror
LDFLAGS = -rcs

all:$(NAME)

$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $(NAME) $(OBJS) 

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

so:
	$(CC) -fPIC $(CFLAGS) $(SRCS) -c
	gcc -shared -o libft.so $(OBJS)

re: fclean all

.PHONY: all fclean clean re
