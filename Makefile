# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 16:20:14 by gdelabro          #+#    #+#              #
#    Updated: 2016/12/13 13:11:55 by gdelabro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fdf

SRC = src/main.c src/ft_file_to_tab.c src/ft_color.c

OBJ = main.o ft_file_to_tab.o ft_color.o

all : $(NAME)

$(NAME) :
	@make -C libft
	@echo "creation de libft [OK]"
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@echo "creation fichier objet [OK]"
	@gcc -o $(NAME) $(OBJ) -L libft -lft -lm -lmlx -framework OpenGL -framework AppKit
	@echo "creation executable [OK]"

clean :
	@make -C libft clean
	@echo "suppression .o libft [OK]"
	@rm -rf $(OBJ)
	@echo "suppression .o Fdf [OK]"

fclean : clean
	@make -C libft fclean
	@echo "suppression libft.a [OK]"
	@rm -rf $(NAME)
	@echo "suppression executable Fdf [OK]"

re : fclean all
