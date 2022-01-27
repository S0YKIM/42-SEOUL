# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 21:27:39 by sokim             #+#    #+#              #
#    Updated: 2022/01/27 21:18:04 by sokim            ###   ########.fr        #
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
	   src/status.c \
	   src/hook.c \
	   src/draw.c \
	   src/utils.c

SRCS_B = bonus/main_bonus.c \
		 bonus/parse_bonus.c \
		 bonus/check_bonus.c \
		 bonus/window_bonus.c \
		 bonus/image_bonus.c \
		 bonus/status_bonus.c \
		 bonus/hook_bonus.c \
		 bonus/draw_bonus.c \
		 bonus/utils_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

GNL = gnl
SRCS_GNL = libs/gnl/get_next_line.c
OBJS_GNL = $(SRCS_GNL:.c=.o)

LIBFT = libft
LIBFT_FLAGS = -L libs/libft -lft

MLX = mlx
MLX_FLAGS = -L libs/mlx -lmlx -framework OpenGL -framework Appkit

INC_FLAGS = -I includes -I includes/$(NAME) -I includes/so_long_bonus -I libs/$(LIBFT) -I libs/$(GNL) -I libs/$(MLX)

ifdef WITH_BONUS
	SRCS_SL = $(SRCS_B)
	OBJS_SL = $(OBJS_B)
else
	SRCS_SL = $(SRCS)
	OBJS_SL = $(OBJS)
endif

ifdef WITH_BONUS
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)
else
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)
endif

all : $(LIBFT) $(MLX) $(NAME)
	$(info <MAKE> all$)

$(LIBFT) :
	@make --silent --directory=libs/$(LIBFT)
	$(info $<MAKE>	Libft - make$)

$(MLX) :
	@make --silent --directory=libs/$(MLX)
	$(info $<MAKE>	MinilibX - make$)

$(NAME) : $(OBJS_SL) $(OBJS_GNL)
	$(info $<MAKE> NAME$)
	$(CC) $(CFLAGS) -o $@ $(OBJS_SL) $(OBJS_GNL) $(LIBFT_FLAGS) $(MLX_FLAGS)

bonus : 
	make WITH_BONUS=1 all

clean :
	@make clean --directory=libs/$(LIBFT)
	@make clean --directory=libs/$(MLX)
	rm -rf $(OBJS) $(OBJS_B) $(OBJS_GNL)

fclean : clean
	@make fclean --directory=libs/$(LIBFT)
	rm -rf $(NAME)

re :	fclean all

.PHONY : all clean fclean re bonus $(LIBFT) $(MLX) $(NAME)
