NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

FILES_LIBC = ft_memset \
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
		ft_strdup

FILES_ADDITIONAL = ft_itoa \
				ft_putchar_fd \
				ft_putstr_fd \
				ft_putendl_fd \
				ft_putnbr_fd \
				ft_substr \
				ft_strjoin \
				ft_strtrim \
				ft_split \
				ft_strmapi	

FILES_BONUS = ft_lstnew \
	  		ft_lstadd_front \
	  		ft_lstsize \
	  		ft_lstlast \
	  		ft_lstadd_back \
	  		ft_lstdelone \
	  		ft_lstclear \
	  		ft_lstiter \
	  		ft_lstmap

LIBC_DIR = ./LIBC/
ADDITIONAL_DIR = ./ADDITIONAL/
BONUS_DIR = ./BONUS/

SRCS_LIBC = $(addprefix $(LIBC_DIR), $(addsuffix .c, $(FILES_LIBC)))
SRCS_ADDITIONAL = $(addprefix $(ADDITIONAL_DIR), $(addsuffix .c, $(FILES_ADDIIONAL)))
SRCS_BONUS = $(addprefix $(BONUS_DIR), $(addsuffix .c, $(FILES_BONUS)))

OBJS_LIBC = $(addprefix $(LIBC_DIR), $(addsuffix .o, $(FILES_LIBC)))
OBJS_ADDITIONAL = $(addprefix $(ADDITIONAL_DIR), $(addsuffix .o, $(FILES_ADDITIONAL)))
OBJS_BONUS = $(addprefix $(BONUS_DIR), $(addsuffix .o, $(FILES_BONUS)))

INC_FLAGS = -I ./

ifdef WITH_BONUS
	SRCS_FILES = $(SRCS_LIBC) $(SRCS_ADDITIONAL) $(SRCS_BONUS)
	OBJ_FILES = $(OBJS_LIBC) $(OBJS_ADDITIONAL) $(OBJS_BONUS)
else
	SRCS_FILES = $(SRCS_LIBC) $(SRCS_ADDITIONAL)
	OBJ_FILES = $(OBJS_LIBC) $(OBJS_ADDITIONAL)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $@ $^

bonus:
	make WITH_BONUS=1 all

.c.o: $(SRCS_FILES)
	$(CC) $(CFLAGS) -c -o $@ $< $(INC_FLAGS)

clean:
	$(RM) $(OBJS_LIBC) $(OBJS_ADDITIONAL) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
