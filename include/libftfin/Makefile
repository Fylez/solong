# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liam <liam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 16:03:42 by lzaengel          #+#    #+#              #
#    Updated: 2023/10/10 16:52:13 by liam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := libft.a
CC        := gcc
FLAGS    := -g -Wall -Wextra -Werror 

SRCS        :=			ft_toupper.c \
                          ft_isascii.c \
                          ft_memcpy.c \
						  ft_memset.c \
                          ft_isalpha.c \
                          ft_isprint.c \
                          ft_tolower.c \
                          ft_isdigit.c \
                          ft_isalnum.c \
						  ft_strdup.c \
						  ft_strlen.c \
						  ft_strlcat.c \
						  ft_strlcpy.c \
						  ft_strncmp.c \
						  ft_strnstr.c \
						  ft_bzero.c \
						  ft_strchr.c \
						  ft_memmove.c \
						  ft_memcmp.c \
						  ft_calloc.c \
						  ft_memchr.c \
						  ft_atoi.c \
						  ft_strrchr.c \
						  ft_strmapi.c \
						  ft_substr.c \
						  ft_strjoin.c \
						  ft_strtrim.c \
						  ft_putchar_fd.c\
							ft_putstr_fd.c\
							ft_putendl_fd.c\
							ft_putnbr_fd.c\
							ft_split.c\
							ft_striteri.c\
							ft_itoa.c\
							ft_lstnew.c\
							ft_lstadd_front.c\
							ft_lstlast.c\
							ft_lstsize.c\
							ft_lstdelone.c\
							ft_lstadd_back.c\
							ft_lstclear.c\
							ft_lstiter.c\
							ft_lstmap.c\
							ft_printf.c \
							ft_printf_hexa.c \
							ft_putchar.c \
							ft_putstr.c \
							ft_putnbr.c \
							get_next_line.c \
							get_next_line_utils.c 

OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

RM		    := rm -f

${NAME}:	${OBJS}

			ar rc ${NAME} ${OBJS}

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o

fclean:		clean
			@ ${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re


