# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mescande <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 11:37:26 by mescande          #+#    #+#              #
#    Updated: 2019/05/04 12:39:49 by mescande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAGS = -Wall -Werror -Wextra

SRC_DIR = ./
OBJ_DIR = obj/
INC_DIR = ./\
		  ./libft/
SRC_LIST = main.c\
		   verif_file.c\
		   fillit.c

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))
DIR = $(sort $(dir $(OBJ)))
INC = $(INC_DIR:%=-I %)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(DIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@ $(INC)

$(DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean flean re

-include $(OBJ:.o=.d)
