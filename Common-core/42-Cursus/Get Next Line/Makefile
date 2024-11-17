# **************************************************************************** #
#                                 VARIÁVEIS                                    #
# **************************************************************************** #

# Nome da biblioteca
NAME = get_next_line.a

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE = 42  # Valor padrão de BUFFER_SIZE, pode ser alterado na execução

# Pastas
SRC_DIR = srcs
BONUS_DIR = bonus
OBJ_DIR = obj
INC_DIR = includes
TEST_DIR = tests

# Arquivos SRCS e bônus
SRCS = $(SRC_DIR)/get_next_line.c \
        $(SRC_DIR)/get_next_line_utils.c

BONUS_SRCS = $(BONUS_DIR)/get_next_line_bonus.c \
              $(BONUS_DIR)/get_next_line_utils_bonus.c
             
# Cria os arquivos objetos principais e de bônus
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRCS:.c=.o)))

# Arquivos de teste
TEST_MAIN = $(TEST_DIR)/main.c
BONUS_TEST_MAIN = $(TEST_DIR)/main_bonus.c

EXECUTE_TEST = ./a.out
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

# Regras para compilar arquivos .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -I $(INC_DIR) -o $@ -c $<
	@echo "Compiled: $<"

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -I $(INC_DIR) -o $@ -c $<
	@echo "Compiled bonus: $<"

# Regra bonus: Compila os arquivos de bônus e cria a biblioteca
bonus: $(NAME) $(OBJS_BONUS)
	@$(COMPRESS) $(NAME) $(OBJS_BONUS)
	@echo "Bonus added to $(NAME)!"

# Regra para compilar e executar o teste principal
test: $(NAME)
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -I $(INC_DIR) $(TEST_MAIN) $(NAME) -o $(EXECUTE_TEST)
	@$(EXECUTE_TEST)

# Regra para compilar e executar o teste bônus
test_bonus: bonus
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -I $(INC_DIR) $(BONUS_TEST_MAIN) $(NAME) -o bonus_test
	@./bonus_test

# Limpeza
clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "Cleaned up object files."

fclean: clean
	@$(RM) $(NAME) $(EXECUTE_TEST) bonus_test
	@echo "All cleaned up: $(NAME), $(EXECUTE_TEST) and bonus_test!"

re: fclean all

.PHONY: all clean fclean re bonus test test_bonus

