# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 16:20:14 by gdelabro          #+#    #+#              #
#    Updated: 2016/12/09 16:50:52 by gdelabro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fdf

SRC = src/main.c src/ft_file_to_tab.c

OBJ = main.o ft_file_to_tab.o

all : NAME

NAME :
	@cd libft && make re && cd ..
	@echo "comilation Libft.a [OK]"
	@gcc -c -Wall -Wextra -Werror $(SRC)
	@echo "creation fichier objet [OK]"
	@gcc -o $(NAME) $(OBJ) -L libft -lft -lm -lmlx -framework OpenGL -framework AppKit
	@echo "creation executable [OK]"

clean :
	@cd libft && make clean && cd ..
	@echo "suppression .o libft [OK]"
	@rm -rf $(OBJ)
	@echo "suppression .o Fdf [OK]"

fclean : clean
	@cd libft && make fclean && cd ..
	@echo "suppression libft.a [OK]"
	@rm -rf $(NAME)
	@echo "suppression executable Fdf [OK]"

re : fclean all
