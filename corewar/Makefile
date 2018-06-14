# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 20:57:47 by mpascaud          #+#    #+#              #
#    Updated: 2018/06/05 22:42:26 by kgricour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
CC = gcc
FLAG = -g #-Wall -Wextra -Werror -g 
INC_DIR = includes
SRCS_DIR_ASM = srcs/
OBJS_DIR = objs
SRCS_NAME = corewar.c ft_check_champ.c

OBJS_NAME = $(SRCS_NAME:.c=.o)
LIB_DIR = libft/
LIB = libftprintf.a

SRCS = $(addprefix $(SRCS_DIR_ASM)/, $(SRCS_NAME))
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_NAME))

INCLUDE = -I $(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	    Make -C $(LIB_DIR)
		    $(CC) $(FLAG) $^ -o $@ $(LIB_DIR)/$(LIB)

$(OBJS_DIR)/%.o: $(SRCS_DIR_ASM)/%.c
	    @mkdir -p $(OBJS_DIR)
		    $(CC) $(FLAG) $(INCLUDE) -c $^ -o $@

clean:
	    $(RM) -r $(OBJS_DIR)

fclean: clean
	    $(RM) $(NAME)

re: fclean all
