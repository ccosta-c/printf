# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 13:40:24 by ccosta-c          #+#    #+#              #
#    Updated: 2023/01/02 16:19:40 by ccosta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_hex.c ft_printf.c ft_char.c ft_integer.c

OBJS := $(SRC:.c=.o)

COMPILER = cc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) 

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re