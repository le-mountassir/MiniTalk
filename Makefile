# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 14:32:16 by ahel-mou          #+#    #+#              #
#    Updated: 2021/12/13 17:07:40 by ahel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minitalk.a

FLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf/src/ft_printf.c\
		ft_printf/src/var_type.c\
		ft_printf/src/ft_putchar.c\
		ft_printf/src/ft_putstr.c\
		ft_printf/src/ft_putnbr_base_unsigned.c\
		ft_printf/src/ft_strlen.c\
		ft_printf/src/ft_putnbr_base.c\
		ft_printf/src/ft_pt_address.c\
		ft_printf/src/base_num_len.c\
		utils/ft_atoi.c\
		utils/to_binary.c\
		utils/to_ascii.c
		
	
CC = gcc

FLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

all: $(NAME) client server

$(NAME) : $(OBJS)
	@$(CC) -c $(CFLAGS) $(SRCS)
	@ar -rcs $(NAME) $(OBJS)

clean:
	find . -name "*.o" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

server:
	gcc server.c $(SRCS) -o server
	@clear
	@./server

client:
	gcc client.c $(SRCS) -o client
	@clear

.PHONY: clean, fclean, all, re, server, client