# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 11:56:15 by sokim             #+#    #+#              #
#    Updated: 2022/07/07 16:56:49 by sokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fragtrap

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = src/main.cpp \
		src/ClapTrap.cpp \
		src/ScavTrap.cpp \
		src/FragTrap.cpp
OBJS = $(SRCS:.cpp=.o)

INC_DIR = inc

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -I $(INC_DIR)

.PHONY : all clean fclean re
