#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 18:10:12 by abrichar          #+#    #+#              #
#    Updated: 2018/05/04 02:37:48 by abrichar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = asm

CFLAG = -Wall -Wextra -Werror -g
CPPFLAGS = -Iincludes

SRC_NAME = main.c line.c parsing.c utilities.c dump_header.c \
			add_op.c check_op.c op1.c op2.c op3.c op4.c utilities2.c \
			writend.c op.c prog_size.c write_params.c utilities3.c \
			write_label.c free_all.c

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_PATH = src
OBJ_PATH = obj
INC_PATH = includes
LIB_PATH = ../libft

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH)/, libft.a)

all: $(NAME)

$(LIB):
	@make -C ../libft

$(NAME): $(OBJ) $(LIB)
	@gcc $(CFLAG) $(SRC) $(LIB) -o $(NAME) -I $(INC_PATH) -I../libft/includes

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@rm -rf $(LIB_PATH)/obj

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB)

re: fclean all

norme:
	norminette $(SRC)
	norminette ./includes/asm.h
