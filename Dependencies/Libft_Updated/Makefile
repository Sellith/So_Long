TARGET		=	$(BIN_DIR)/libft.a
COMPILER	=	gcc
CFLAGS 		=	-Werror -Wextra -Wall -g

BUILD_DIR 	=	../../build/libft
BIN_DIR		=	../../bin/archives
GNL_DIR		=	get_next_line
SRC_DIR		=	src

RED			=	\033[31m
GRN			=	\033[92m
YLW			=	\033[33m
CRESET		=	\033[0m

LIBC		=	ft_isalpha.c ft_isprint.c ft_strlen.c ft_bzero.c \
				ft_isascii.c ft_memcpy.c ft_isalnum.c ft_isdigit.c \
				ft_memset.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
				ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_arraydup.c ft_datola.c \
				ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_strcpy.c \
				ft_isnum.c ft_atol.c ft_putdarray.c ft_putlarray.c ft_datoia.c \
				ft_strstr.c ft_darraylen.c ft_strcat.c ft_strjoining.c \
				get_next_line.c get_next_line_utils.c


OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(LIBC))

all: $(TARGET)

stealth: all clean

$(TARGET):  $(LIBFT_TARGET) $(OBJS)
	@$(MAKE) -C $(SRC_DIR)/ft_printf/ --no-print-directory
	@printf "$(GRN)Info : Compilation de la libft réussie !\n$(CRESET)"
	@mkdir -p $(BIN_DIR)
	@ar rcs $(TARGET) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C $(SRC_DIR)/ft_printf/ --no-print-directory
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(SRC_DIR)/ft_printf/ --no-print-directory
	@rm -f $(TARGET)

stealth_re: fclean all
	@rm -f $(OBJS)

re: fclean all

.PHONY: stealth all clean fclean stealth_re re


