# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 13:40:24 by ccosta-c          #+#    #+#              #
#    Updated: 2023/01/04 11:42:54 by ccosta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_hex.c ft_printf.c ft_char.c ft_integer.c ft_string.c ft_unsigned.c

OBJS := $(SRC:.c=.o)

COMPILER = cc

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) 

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)
	
run: fclean all
	$(COMPILER) $(FLAGS) $(SRC)
	./a.out

re: fclean all

.PHONY: all clean fclean re