SRC = main.c mapinit.c movement.c map_check.c exit.c

LIBFTDIR = include/libftfin/

LIBFT = include/libftfin/libft.a

CC = gcc

NAME = so_long

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(SRC) -Lmlx_linux -lmlx_Linux -L/usr/lib -g -Imlx_linux -lXext -lX11 -lm -lz -L$(LIBFTDIR) -lft -o $(NAME)

$(LIBFT):
		$(MAKE) -C $(LIBFTDIR)

all:		${NAME}

clean :
	$(MAKE) -C $(LIBFTDIR) fclean
fclean: clean
		rm $(NAME)