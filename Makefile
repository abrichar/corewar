# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 20:57:47 by mpascaud          #+#    #+#              #
#    Updated: 2018/07/03 01:06:07 by kgricour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VM = corewar
ASM = asm
DIR_ASM = dir_asm/
DIR_VM = dir_corewar/

all: $(ASM) $(VM)

$(ASM):
	    Make -C $(DIR_ASM)
		mv $(DIR_ASM)$(ASM) .
$(VM): 
		Make -C $(DIR_VM)
		mv $(DIR_VM)$(VM) .	
clean:
	    Make clean -C $(DIR_ASM)
	    Make clean -C $(DIR_VM)

fclean: clean
	    Make fclean -C $(DIR_ASM)
	    Make fclean -C $(DIR_VM)
		$(RM) $(ASM)
		$(RM) $(VM)

re: fclean all
