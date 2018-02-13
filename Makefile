# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msicot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 18:38:05 by msicot            #+#    #+#              #
#    Updated: 2018/02/13 13:34:03 by msicot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re

SRC_PATH = ./src/
INC_PATH = ./inc/
OBJ_PATH = ./obj/

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wextra -Werror -Wall

SRC_NAME = ft_printf.c ft_error.c ft_flags.c	ft_format.c	ft_integer.c	ft_is_type.c	ft_itoa_max.c	ft_options.c	ft_printf.c	ft_read.c\
	   	   ft_is_num.c ft_is_c.c ft_is_p.c	ft_is_unic.c ft_is_unis.c ft_string.c ft_octal.c ft_octal2.c	ft_itoa_base.c	ft_itoa_base_u.c	ft_width.c ft_sign.c \
		   ft_precision.c ft_is_u.c ft_itoa_usigned.c ft_width_o.c ft_width_x.c ft_hexa.c ft_hexa2.c ft_null.c ft_pourc.c
		
OBJ_NAME = $(SRC_NAME:.c=.o)

complete = @echo "\033[92mComplete\033[0m"
cleaning = @echo "\033[36mCleaning complete\033[0m"

LIB_INC = -I./libft/inc/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH)) $(LIB_INC)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Generating objects for the printflib"
	@make -C ./libft
	@echo "***********************************"
	@echo "Building printf"
	@ar rc $(NAME) $(OBJ)
	@echo "Compiling sources into a library"
	@ranlib	$(NAME)
	$(complete)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<	

clean : 
	@echo "**********************************"
	@make clean -C ./libft
	$(cleaning)
	@echo "Removing printf's binaries"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	$(cleaning)

fclean : clean
	@echo "*********************************"
	@make fclean -C ./libft
	@rm -f $(NAME)

re : fclean all

m : all
	@clear
	@gcc main.c -L. -lftprintf
