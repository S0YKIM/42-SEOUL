# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/30 21:42:05 by sokim             #+#    #+#              #
#    Updated: 2021/06/11 16:46:11 by sokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft
LIBFT_LIB = libft.a

FILES_UTIL = convert_number \
			 flag \
			 hashtag \
			 init \
			 number

FILES_PRINT = print_char \
			  print_number \
			  print_string

SRC_UTIL_DIR = ./utils/
SRC_UTIL = $(addprefix $(SRC_UTIL_DIR), $(addsuffix .c, $(FILES_UTIL)))

SRC_PRINT_DIR = ./print/
SRC_PRINT = $(addprefix $(SRC_PRINT_DIR), $(addsuffix .c, $(FILES_PRINT)))

SRCS = ./ft_printf.c \
	   $(SRC_UTIL) \
	   $(SRC_PRINT)

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

bonus:
	make all

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: fclean all
