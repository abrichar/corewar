# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 20:57:47 by mpascaud          #+#    #+#              #
#    Updated: 2018/06/28 22:42:58 by kgricour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
CC = gcc 
FLAG_NCURSES = -lncurses
FLAG = -Wall -Wextra -Werror 
INC_DIR = includes
SRCS_DIR_ASM = srcs/
OBJS_DIR = objs
SRCS_NAME = corewar.c ft_check_champ.c ft_get_opt.c ft_process.c \
			ft_malloc_vm.c ft_dump.c ft_tool_instruction.c ft_instruction.c\
			ft_instruction_two.c ft_instruction_three.c ft_instruction_four.c\
			ft_instruction_five.c ft_ncurse.c ft_is_win.c ft_view.c \
			ft_parse_instruct.c ft_is_exist.c ft_init_vm.c ft_vm.c \
			ft_free_vm.c ft_adress_champ.c ft_check_and_start.c
OBJS_NAME = $(SRCS_NAME:.c=.o)
LIB_DIR = libft/
LIB = libftprintf.a

SRCS = $(addprefix $(SRCS_DIR_ASM)/, $(SRCS_NAME))
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_NAME))

INCLUDE = -I $(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	    Make -C $(LIB_DIR)
		    $(CC) $(FLAG) $(FLAG_NCURSES) $^ -o $@ $(LIB_DIR)/$(LIB)

$(OBJS_DIR)/%.o: $(SRCS_DIR_ASM)/%.c
	    @mkdir -p $(OBJS_DIR)
		    $(CC) $(FLAG) $(INCLUDE) -c $^ -o $@

clean:
	    $(RM) -r $(OBJS_DIR)

fclean: clean
	    $(RM) $(NAME)

re: fclean all
