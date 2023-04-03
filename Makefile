# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 15:19:43 by jlaiti            #+#    #+#              #
#    Updated: 2023/04/03 18:32:21 by jlaiti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -g -pthread
RM = rm-rf

SRC =	parse_args.c		\
	main.c			\
	philo_utils.c		\
	run_philo.c		\

SRC_DIR = $(addprefix src/, $(SRC))
OBJ = ${SRC_DIR:.c=.o}

NAME = philo

INCLUDES = -Iinclude/

all : ${NAME}

%.o: %.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@ -I

${NAME}: ${OBS}
	${CC} ${FLAGS} -L. -o ${NAME} ${OBS}

re: fclean all

clean:
	${RM} src/main.c
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

.PHONY: all re clean fclean
