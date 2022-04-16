# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 10:26:20 by nbenjami          #+#    #+#              #
#    Updated: 2021/12/08 16:51:33 by nbenjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST = ft_printf.c\
		ft_ulits.c\
		ft_hexa.c\
		ft_chars.c\
		ft_pointers.c\

OBJ = $(patsubst %.c, %.o,$(LIST))

INC = ft_printf.h

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c $(INC) Makefile
		cc $(FLAGS) -c $< -o $@ -I $(INC)

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re