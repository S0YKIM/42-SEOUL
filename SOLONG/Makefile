# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 21:27:39 by sokim             #+#    #+#              #
#    Updated: 2022/01/21 17:23:37 by sokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c \
	   src/parse.c \
	   src/check.c \
	   src/window.c \
	   src/image.c \
	   src/status.c

OBJS = $(SRCS:.c=.o)

GNL = gnl
SRCS_GNL = libs/gnl/get_next_line.c \
		   libs/gnl/get_next_line_utils.c
OBJS_GNL = $(SRCS_GNL:.c=.o)

LIBFT = libft
LIBFT_FLAGS = -L libs/libft -lft

MLX = mlx
MLX_FLAGS = -L libs/mlx -lmlx -framework OpenGL -framework Appkit

INC_FLAGS = -I includes -I includes/$(NAME) -I libs/$(LIBFT) -I libs/$(GNL) -I libs/$(MLX)

all : $(LIBFT) $(MLX) $(NAME)
	$(info <MAKE> all$)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)

$(LIBFT) :
	@make --silent --directory=libs/$(LIBFT)
	$(info $<MAKE>	Libft - make$)

$(MLX) :
	@make --silent --directory=libs/$(MLX)
	$(info $<MAKE>	MinilibX - make$)

$(NAME) : $(LIBFT) $(MLX) $(OBJS) $(OBJS_GNL)
	$(info $<MAKE> NAME$)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(OBJS_GNL) $(LIBFT_FLAGS) $(MLX_FLAGS)

clean :
	@make clean --directory=libs/$(LIBFT)
	@make clean --directory=libs/$(MLX)
	rm -rf $(OBJS) $(OBJS_GNL)

fclean : clean
	@make fclean --directory=libs/$(LIBFT)
	rm -rf $(NAME)

re :	fclean all

.PHONY : all clean fclean re libft mlx
