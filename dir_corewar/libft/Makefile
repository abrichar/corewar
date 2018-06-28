# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgricour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:06:47 by kgricour          #+#    #+#              #
#    Updated: 2018/05/31 19:08:43 by kgricour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

SRC =	ft_atod.c ft_isalnum.c ft_isascii.c ft_isblank.c ft_isprint.c \
		ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
		ft_lstnew.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memmove.c \
		ft_strequ.c ft_striter.c ft_strlcat.c ft_strmap.c ft_strmapi.c \
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnstr.c \
		ft_strsplit.c ft_strtrim.c ft_tolower.c ft_toupper.c get_next_line.c\
		ft_strclr.c ft_strlen.c ft_strnew.c ft_putchar.c ft_putstr.c \
		ft_strdel.c ft_strdup.c ft_memalloc.c ft_memdel.c ft_memset.c \
		ft_strchr.c ft_strrchr.c ft_strstr.c ft_atoi.c ft_strcat.c \
		ft_isdigit.c ft_strsub.c ft_strjoin.c ft_itoa.c ft_putnbr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_nbrlen.c ft_sqrt.c \
		ft_bzero.c ft_strcmp.c ft_freejoin.c ft_putadr.c ft_printf_fd.c \
		ft_printf_sc.c ft_printf_id.c ft_printf_parse.c ft_printf_pct.c \
		ft_printf_tool.c ft_printf_xobup.c ft_putwchar.c ft_printf_dot.c \
		ft_isalpha.c ft_islower.c ft_isupper.c ft_strchrstr.c ft_strncpy.c \
		ft_memcpy.c ft_putendl.c ft_putendl_fd.c ft_save_val_opt.c ft_printf_c.c \
		ft_dbl_malloc.c ft_strcpy.c
		
OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all :  $(NAME)

%.o: %.c
	$(CC) $(FLAG) -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -fR $(SRC:.c=.o)

fclean : clean
	rm -fR $(NAME)

re : fclean all

.PHONY : all clean fclean re
