# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/09 00:23:24 by rmedeiro          #+#    #+#              #
#    Updated: 2025/04/09 00:42:15 by rmedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome da biblioteca
NAME = libft.a

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

RM = rm -f
COMPRESS = ar rcs

# Pastas
SRC_DIR = srcs
BONUS_DIR = bonus
OBJ_DIR = obj
INC_DIR = includes

# Subpastas
FD_DIR = fd
MEMORY_DIR = memory
STRINGS_DIR = strings
UTILS_DIR = utils

SRCS = $(addprefix $(SRC_DIR)/$(FD_DIR)/, ft_putchar_fd.c ft_putendl_fd.c \
        ft_putnbr_fd.c ft_putstr_fd.c) \
       $(addprefix $(SRC_DIR)/$(MEMORY_DIR)/, ft_bzero.c ft_calloc.c \
	    ft_memchr.c \ ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c) \
       $(addprefix $(SRC_DIR)/$(STRINGS_DIR)/, ft_split.c ft_strchr.c ft_strdup.c \
	    ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		ft_substr.c) \
       $(addprefix $(SRC_DIR)/$(UTILS_DIR)/, ft_atoi.c ft_isalnum.c ft_isalpha.c \
	   ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_tolower.c ft_toupper.c)

BONUS_SRCS = $(addprefix $(BONUS_DIR)/, ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c)

# Cria os arquivos objetos principais e os de bónus
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

# Regra all: Compila os arquivos principais e cria a biblioteca
all: $(NAME)

$(NAME): $(OBJS)
	@$(COMPRESS) $(NAME) $(OBJS)
	@echo "Library $(NAME) created successfully!"

# Regra para compilar arquivos .o a partir dos arquivos .c e criar a pasta
$(OBJ_DIR)/$(SRC_DIR)/$(FD_DIR)/%.o: $(SRC_DIR)/$(FD_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(FD_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

$(OBJ_DIR)/$(SRC_DIR)/$(MEMORY_DIR)/%.o: $(SRC_DIR)/$(MEMORY_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(MEMORY_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

$(OBJ_DIR)/$(SRC_DIR)/$(STRINGS_DIR)/%.o: $(SRC_DIR)/$(STRINGS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(STRINGS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

$(OBJ_DIR)/$(SRC_DIR)/$(UTILS_DIR)/%.o: $(SRC_DIR)/$(UTILS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(UTILS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

# Regra para compilar arquivos bónus a partir da pasta bónus
$(OBJ_DIR)/$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/$(BONUS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled bonus: $<"

# Regra para compilar a biblioteca incluindo os bónus
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
