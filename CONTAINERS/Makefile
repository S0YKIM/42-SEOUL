# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 19:27:06 by sokim             #+#    #+#              #
#    Updated: 2022/12/14 19:27:26 by sokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = src/main.cpp
OBJS = $(SRCS:.cpp=.o)

INC_DIR = inc

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(INC_DIR)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) -I $(INC_DIR)

.PHONY : all clean fclean re
