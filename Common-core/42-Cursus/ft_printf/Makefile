# **************************************************************************** #
#                                 VARIÁVEIS                                    #
# **************************************************************************** #

# Nome da biblioteca
NAME = libftprintf.a

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

# Pastas
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes

# Variáveis do Libft
LIBFT_DIR = ../Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Arquivos SRCS
SRCS = $(SRC_DIR)/ft_printf.c \
        $(SRC_DIR)/ft_print_x.c \
        $(SRC_DIR)/ft_print_p.c \
        $(SRC_DIR)/ft_print_u.c \
        $(SRC_DIR)/ft_print_d.c \
        $(SRC_DIR)/ft_print_s.c \
        $(SRC_DIR)/ft_print_c.c

# Cria os arquivos objetos principais
OBJ = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

RM = rm -f
COMPRESS = ar rcs

# **************************************************************************** #
#                                COMPILAÇÃO                                    #
# **************************************************************************** #

# Regra all: Compila os arquivos principais e cria a biblioteca
all: $(NAME)

# Regra para criar a biblioteca
$(NAME): $(LIBFT) $(OBJ)
	@$(COMPRESS) $(NAME) $(OBJ) $(LIBFT)
	@echo "Library $(NAME) created successfully!"

# Regra para compilar arquivos .o a partir dos arquivos .c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

# Regra para compilar a libft se necessário
$(LIBFT): 
	@$(MAKE) -C $(LIBFT_DIR)

# Regra clean: Remove os arquivos objetos (.o)
clean:
	@$(RM) $(OBJ)
	@if [ -d "$(OBJ_DIR)" ]; then rmdir $(OBJ_DIR); fi
	@echo "Printf: Obj cleaned"

# Regra fclean: Remove os arquivos objetos (.o) e a biblioteca
fclean: clean
	@$(RM) $(NAME)
	@echo "Printf: Exec cleaned"

# Regra re: Limpa tudo e recompila
re: fclean all

# Regra para a libft
libft: $(LIBFT)

.PHONY: all clean fclean re libft

