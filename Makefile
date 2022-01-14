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

NAME = server
NAME_C = client

CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

HEADER = ./inc/minitalk.h

SRC = ./src/ft_utils.c
SRC_S = ./src/server.c
SRC_S_B = ./src/server_bonus.c
SRC_C = ./src/client.c
SRC_C_B = ./src/client_bonus.c

OBJ = $(patsubst %.c,%.o,$(SRC))
OBJ_S = $(patsubst %.c,%.o,$(SRC_S))
OBJ_C = $(patsubst %.c,%.o,$(SRC_C))
OBJ_S_B = $(patsubst %.c,%.o,$(SRC_S_B))
OBJ_C_B = $(patsubst %.c,%.o,$(SRC_C_B))

all:	$(NAME) $(NAME_C)

bonus:	$(OBJ) $(OBJ_S_B) $(OBJ_C_B)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_S_B) -o $(NAME)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_C_B) -o $(NAME_C)

$(NAME):	$(OBJ) $(OBJ_S)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_S) -o $(NAME)

$(NAME_C):	$(OBJ) $(OBJ_C)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_C) -o $(NAME_C)

%.o:	%.c Makefile $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:	
	$(RM) $(OBJ) $(OBJ_S) $(OBJ_C) $(OBJ_S_B) $(OBJ_C_B)

fclean:	clean
	$(RM) server client

re: fclean all

.PHONY: all clean fclean re bonus