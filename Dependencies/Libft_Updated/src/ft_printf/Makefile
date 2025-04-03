TARGET		=	$(BIN_DIR)/printf.a
COMPILER	=	gcc
CFLAGS 		=	-Werror -Wextra -Wall -g

BUILD_DIR 	=	../../../../build/ft_printf
BIN_DIR		=	../../../../bin/archives
SRC_DIR		=	.

RED			=	\033[31m
GRN			=	\033[92m
YLW			=	\033[33m
CRESET		=	\033[0m

SRC			=	ft_printf_putchar.c ft_printf_puthexa.c ft_printf_putnumber.c ft_printf_putpointer.c \
				ft_printf_putstring.c ft_printf_putunsigned.c ft_printf.c ft_printf_puterror.c \
				ft_printf_putdarray.c

OBJS		=	$(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p  $(BIN_DIR)
	@ar rcs $(TARGET) $(OBJS)
	@printf "$(GRN)Info : Compilation de ft_printf réussie !$(CRESET)\n"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
