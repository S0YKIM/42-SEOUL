# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 17:52:20 by sokim             #+#    #+#              #
#    Updated: 2021/07/01 21:59:07 by sokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft
LIB = ./libft/libft.a

FILES_SRCS = pipex \
			 redirect \
			 command \
			 pipe

FILES_SRCS_B = bonus/pipex_bonus \
			   bonus/heredoc_bonus \
			   bonus/redirect_bonus \
			   bonus/command_bonus \
			   bonus/pipe_bonus \
			   bonus/get_next_line \

SRCS_DIR = ./srcs/
SRCS_M = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_SRCS)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_SRCS_B)))

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

INCS = ./includes
RM = rm -f
AR = ar rc

ifdef WITH_BONUS
	SRCS = $(SRCS_B)
	OBJS = $(OBJS_B)
else
	SRCS = $(SRCS_M)
	OBJS = $(OBJS_M)
endif

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCS)

$(NAME): $(OBJS)
	make all -C $(LIBFT)/
	$(CC) -o $(NAME) $(OBJS) $(LIB)

all: $(NAME)

bonus:
	make WITH_BONUS=1 all

clean:
	$(RM) $(OBJS_M) $(OBJS_B)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re
