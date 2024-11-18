# **************************************************************************** #
#                                 VARIÁVEIS                                    #
# **************************************************************************** #

# Nome da biblioteca
NAME = libftprintf.a

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

# Pastas
BONUS_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes

# Variáveis do Libft
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Arquivos SRCS
SRCS = $(BONUS_DIR)/ft_printf.c \
        $(BONUS_DIR)/ft_print_x.c \
        $(BONUS_DIR)/ft_print_p.c \
        $(BONUS_DIR)/ft_printf_utils.c \
        $(BONUS_DIR)/ft_print_d.c \
        $(BONUS_DIR)/ft_print_s.c \
        $(BONUS_DIR)/ft_print_c.c

# Cria os arquivos objetos principais
OBJ = $(SRCS:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

RM = rm -f
COMPRESS = ar rcs
RANLIB = ranlib

# **************************************************************************** #
#                                COMPILAÇÃO                                    #
# **************************************************************************** #

# Regra all: Compila os arquivos principais e cria a biblioteca
all: $(NAME)

# Regra para criar a biblioteca
$(NAME): $(LIBFT) $(OBJ)
	@$(COMPRESS) $(NAME) $(OBJ) $(LIBFT)
	@$(RANLIB) $(NAME)  # Adiciona o índice de símbolos
	@echo "Library $(NAME) created successfully!"

# Regra para compilar arquivos .o a partir dos arquivos .c
$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)  # Garante que o diretório de objetos seja criado
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

