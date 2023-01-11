# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 19:27:06 by sokim             #+#    #+#              #
#    Updated: 2023/01/11 16:10:53 by sokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = src/main.cpp
OBJS = $(SRCS:.cpp=.o)

DATA_STRUCTURE_DIR = inc/data_structure
ITERATOR_DIR = inc/iterator
UTILS_DIR = inc/utils
INC_FLAGS = -I $(DATA_STRUCTURE_DIR) -I $(ITERATOR_DIR) -I $(UTILS_DIR)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC_FLAGS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(INC_FLAGS)

.PHONY : all clean fclean re
