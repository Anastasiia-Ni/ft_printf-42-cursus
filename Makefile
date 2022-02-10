# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 11:49:05 by anifanto          #+#    #+#              #
#    Updated: 2021/10/27 19:54:30 by anifanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c				ft_print_char.c			ft_print_hexa.c\
		ft_print_integer.c		ft_print_pointer.c		ft_print_string.c\
		ft_print_unint.c		ft_libf.c				ft_flag.c

SRCS_P = $(addprefix src/, $(SRCS))

OBJS = $(SRCS_P:.c=.o)

IN = -I./inc

FLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

%.o : %.c
	gcc $(FLAGS) -c $< -o $(<:%.c=%.o)

bonus: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
