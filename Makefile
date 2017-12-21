# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msicot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 18:38:05 by msicot            #+#    #+#              #
#    Updated: 2017/12/21 19:37:31 by msicot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re

SRC_NAME = ft_printf.c
OBJ_NAME = $(SRC_NAME:.c = .o)

SRC_PATH = ./src/
INC_PATH = ./inc/
OBJ_PATH = ./obj/

complete = @echo "\033[92mComplete\033[0m"
cleaning = @echo "\033[36mCleaning complete\033[0m"

CC = gcc
CFLAGS = -Wextra -Werror -Wall
NAME = libftprintf.a

LIB = -L./libft/ -lft
LIB_INC = -I./libft/includes

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH) $(LIB_INC))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Generating objects for the printflib"
	@make -C ./libft
	@echo "***********************************"
	@echo "Building printf"
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<	
	@ar rc $(NAME) $(OBJ)
	@echo "Compiling sources into a library"
	@ranlib	$(NAME)
	$(complete)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<	

clean : 
	@echo "**********************************"
	@make clean -C ./libft
	$(cleaning)
	@echo "Removing printf's binaries"
	@rm -f $(OBJ)
	$(cleaning)

fclean : clean
	@echo "*********************************"
	@make fclean -C ./libft
	@rm -f $(NAME)

re : fclean all
