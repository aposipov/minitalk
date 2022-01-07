# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 16:32:59 by lchristi          #+#    #+#              #
#    Updated: 2022/01/07 19:01:46 by lchristi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
#SERVER = server
#CLIENT = client

CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

HEADER = ./inc/minitalk.h

SRC = ./src/ft_utils.c
SRC_S = ./src/server.c
SRC_C = ./src/client.c

OBJ = $(patsubst %.c,%.o,$(SRC))
OBJ_S = $(patsubst %.c,%.o,$(SRC_S))
OBJ_C = $(patsubst %.c,%.o,$(SRC_C))

all:	$(NAME)

$(NAME): $(OBJ) $(OBJ_S) $(OBJ_C)
	$(CC) $(OBJ) $(OBJ_S) -o server $?
	$(CC) $(OBJ) $(OBJ_C) -o client $?

server:	$(OBJ) $(OBJ_S)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_S) -o server 

client:	$(OBJ) $(OBJ_C)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_C) -o client

%.o:	%.c Makefile $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:	
	$(RM) $(OBJ) $(OBJ_S) $(OBJ_C)

fclean:	clean
	$(RM) server client

re: fclean all

.PHONY: all clean fclean re
