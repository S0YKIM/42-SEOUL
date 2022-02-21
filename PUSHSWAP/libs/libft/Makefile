NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

FILES = ft_strlen \
		ft_strlcpy \
		ft_strcmp \
		ft_atoi \
		ft_split \
		ft_itoa \
		ft_putstr_fd \
		ft_putchar_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_isdigit \
		ft_atol \
		ft_memset \
		ft_itoa_binary \
		ft_strjoin \
		ft_strlcat \
		ft_strdup

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(NAME)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
