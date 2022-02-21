NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c \
		srcs/state.c \
		srcs/check.c \
		srcs/parse.c \
		srcs/index.c \
		srcs/operator.c \
		srcs/print.c \
		srcs/sort.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFT_FLAGS = -L libs/libft -lft

DEQUE = deque
DEQUE_FLAGS = -L libs/deque -ldeque

INC_FLAGS = -I includes -I libs/$(LIBFT) -I libs/$(DEQUE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)

all : $(LIBFT) $(DEQUE) $(NAME)
	$(info <MAKE> all$)

$(LIBFT) :
	@make --silent --directory=libs/$(LIBFT)
	$(info $<MAKE>	Libft - make$)

$(DEQUE) :
	@make --silent --directory=libs/$(DEQUE)
	$(info $<MAKE>	Deque - make$)

$(NAME) : $(OBJS)
	$(info $<MAKE> NAME$)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT_FLAGS) $(DEQUE_FLAGS)

bonus : $(NAME)

clean :
	@make clean --directory=libs/$(LIBFT)
	@make clean --directory=libs/$(DEQUE)
	rm -rf $(OBJS)

fclean : clean
	@make fclean --directory=libs/$(LIBFT)
	@make fclean --directory=libs/$(DEQUE)
	rm -rf $(NAME)

re :	fclean all

.PHONY : all clean fclean re bonus