# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 16:02:32 by sokim             #+#    #+#              #
#    Updated: 2022/06/02 13:23:48 by sokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c \
		srcs/init.c \
		srcs/utils.c \
		srcs/validate.c \
		srcs/philo.c
OBJS = $(SRCS:.c=.o)

INC_FLAGS = -I includes

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

bonus : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

test :
	$(CC) $(CFLAGS) -g -o $(NAME) $(SRCS) $(INC_FLAGS)

leak :
	$(CC) $(CFLAGS) -g3 -fsanitize=address -o $(NAME) $(SRCS) $(INC_FLAGS)

.PHONY : all clean fclean re bonus
