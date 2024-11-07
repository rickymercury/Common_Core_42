# **************************************************************************** #
#                                 VARIÁVEIS                                    #
# **************************************************************************** #

# Nome da biblioteca
NAME = libft.a

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

# Pastas
SRC_DIR = srcs
BONUS_DIR = bonus
OBJ_DIR = obj
INC_DIR = includes

# Arquivos SRCS e bônus
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
       ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
       ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
       ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
       ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c 

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c \
             ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
             ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# Cria os arquivos objetos principais e de bônus
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

RM = rm -f
COMPRESS = ar rcs

# **************************************************************************** #
#                                COMPILAÇÃO                                    #
# **************************************************************************** #

# Regra all: Compila os arquivos principais e cria a biblioteca
all: $(NAME)

$(NAME): $(OBJS)
	@$(COMPRESS) $(NAME) $(OBJS)
	@echo "Library $(NAME) created successfully!"

# Regra para compilar arquivos .o a partir dos arquivos .c e criar a pasta
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

# Regra para compilar arquivos bônus a partir da pasta bônus
$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled bonus: $<"

# Regra para compilar a biblioteca incluindo os bônus
bonus: $(NAME) $(OBJS_BONUS)
	@$(COMPRESS) $(NAME) $(OBJS_BONUS)
	@echo "Bonus added to $(NAME)!"

# Regra clean: Remove os arquivos objetos (.o)
clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "Cleaned up object files."

# Regra fclean: Remove os arquivos objetos (.o) e a biblioteca (libft.a)
fclean: clean
	@$(RM) $(NAME)
	@echo "All cleaned up: $(NAME)!"

# Regra re: Limpa tudo e recompila
re: fclean all

.PHONY: all clean fclean re bonus





