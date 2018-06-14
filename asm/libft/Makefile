# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 07:22:10 by abrichar          #+#    #+#              #
#    Updated: 2018/04/10 18:17:50 by eliajin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAG = -Wall -Wextra -Werror
CPPFLAGS = -Iincludes

SRC_NAME = ft_printf.c ft_printf_parser.c ft_printf_core.c ft_c.c ft_smaj.c \
	ft_percent.c ft_s.c ft_unicode.c ft_l.c ft_oux.c ft_x.c \
	ft_invalid_input.c ft_o.c ft_p.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memccpy.c ft_memmove.c ft_memchr.c \
	ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
	ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
	ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c ft_strncmp.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	ft_count_if.c ft_display_file.c ft_foreach.c ft_range.c ft_sort_params.c \
	ft_swap.c ft_isspace.c ft_strexcept.c get_next_line.c match.c nmatch.c \
	ft_itoabaseu.c ft_putnstr.c ft_putzerox.c ft_countnbr.c ft_countunbr.c \
	ft_putnbrwp.c ft_putstrwp.c ft_putunbrwp.c ft_putunbr.c ft_lstaddlast.c \
	ft_epur_str.c

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_PATH = src
OBJ_PATH = obj
INC_PATH = includes

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@rm -rf libft/obj

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

norme:
	norminette $(SRC)
	norminette includes/libft.h
