NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L libs/libft -lft

INC_FLAGS = -I includes -I $(LIBFT_DIR) -I pthread

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)

all : $(NAME)

$(LIBFT) :
	@make --silent --directory=$(LIBFT_DIR)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT_FLAGS)

bonus : $(NAME)

clean :
	@make clean --silent --directory=$(LIBFT_DIR)
	rm -rf $(OBJS)

fclean : clean
	@make fclean --silent --directory=$(LIBFT_DIR)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus