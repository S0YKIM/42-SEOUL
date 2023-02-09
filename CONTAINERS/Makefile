# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 19:27:06 by sokim             #+#    #+#              #
#    Updated: 2023/02/09 14:45:12 by sokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = src/rbtree/_rb_tree.cpp \
	src/test/main.cpp \
	src/test/vector_test.cpp \
	src/test/map_test.cpp \
	src/test/set_test.cpp \
	src/test/stack_test.cpp
OBJS = $(SRCS:.cpp=.o)

SRCS_SUBJECT = src/rbtree/_rb_tree.cpp \
	src/test/subject_main.cpp
OBJS_SUBJECT = $(SRCS_SUBJECT:.cpp=.o)

DATA_STRUCTURE_DIR = inc/data_structure
ITERATOR_DIR = inc/iterator
UTILS_DIR = inc/utils
TEST_DIR = inc/test
INC_FLAGS = -I $(DATA_STRUCTURE_DIR) -I $(ITERATOR_DIR) -I $(UTILS_DIR) -I $(TEST_DIR)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC_FLAGS)

all : $(NAME)

clean :
	rm -rf $(OBJS) $(OBJS_SUBJECT)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

debug : $(OBJS)
	$(CXX) -g3 -fsanitize=address -o $(NAME) $(OBJS) $(INC_FLAGS)

subject : $(OBJS_SUBJECT)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS_SUBJECT) $(INC_FLAGS)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(INC_FLAGS)

.PHONY : all clean fclean re
