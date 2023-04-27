# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 15:19:43 by jlaiti            #+#    #+#              #
#    Updated: 2023/04/27 16:26:45 by jlaiti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -g -pthread -fsanitize=thread
RM = rm -f

SRC =	parse_args.c		\
		philo_utils.c		\
		main.c				\
		manage_philo.c		\
		activity.c			\
		execute_routine.c	\
		print_message.c		\
		handle_philo.c		\
	

SRC_DIR = $(addprefix src/, $(SRC))
OBJ = ${SRC_DIR:.c=.o}

NAME = philo

INCLUDES = -Iinclude/

%.o: %.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

all : ${NAME}

$(NAME): ${OBJ}
	${CC} ${FLAGS} -o ${NAME} ${OBJ}


clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all
.PHONY: all re clean fclean
