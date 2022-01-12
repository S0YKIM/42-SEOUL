NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

FILES = ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memccpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_memset \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strncmp \
		ft_atoi \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_putchar

FILES_B = 	ft_lstnew \
	  		ft_lstadd_front \
	  		ft_lstsize \
	  		ft_lstlast \
	  		ft_lstadd_back \
	  		ft_lstdelone \
	  		ft_lstclear \
	  		ft_lstiter \
	  		ft_lstmap

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B_DIR = ./
SRCS_B = $(addprefix $(SRCS_B_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B_DIR = ./
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))

ifdef WITH_BONUS
	SRCS_FILES = $(SRCS) $(SRCS_B)
	OBJ_FILES = $(OBJS) $(OBJS_B)
else
	SRCS_FILES = $(SRCS)
	OBJ_FILES = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $@ $^

bonus:
	make WITH_BONUS=1 all

.c.o: $(SRCS_FILES)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
