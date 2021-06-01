# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/30 21:42:05 by sokim             #+#    #+#              #
#    Updated: 2021/05/30 22:11:11 by sokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft
LIBFT_LIB = libft.a

SRCS = ./ft_printf.c ./utils.c\
	   ./print_char.c ./print_nbr.c ./print_string.c
OBJS = $(SRCS:.c=.o)
INCS = .
RM = rm -f
AR = ar rc

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCS)

$(NAME): $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: fclean all
