NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

COMPRESS = ar rcs
RM = rm -f

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c 

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	@$(COMPRESS) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	@$(COMPRESS) $(NAME) $(OBJS_BONUS)

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "Cleaned up object files."

fclean: clean
	@$(RM) $(NAME)
	@echo "Fully cleaned $(NAME)."

re: fclean all

debug: CFLAGS += -g3
debug: fclean $(NAME)

.PHONY: all clean fclean re bonus


