OBJ = main.c mapinit.c include/get_next_line.c include/get_next_line_utils.c 
CC = gcc
NAME = so_long
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all:		${NAME}

clean :
	rm $(NAME)