#---------------------------------------------------#
#            information de compilation             #
#---------------------------------------------------#

TARGET			=	$(BIN_DIR)/so_long
TARGET_H_FILE	=	So_Long.h
CC 				=	gcc
CFLAGS 			=	-Wall -Werror -Wextra
MLXFLAGS		=	-L/usr/bin -lX11 -lXext -lXrandr -lXi -lXinerama -lXcursor -lm

#---------------------------------------------------#
#                COLORS DECLARATION                 #
#---------------------------------------------------#

GRN				=	\033[92m
PPL				=	\033[95m
CYAN			=	\033[96m
CRESET			=	\033[0m

#---------------------------------------------------#
#                 DIRECTORY PATHES                  #
#---------------------------------------------------#

SRC_DIR			=	src
BUILD_DIR		=	build
OBJ_SRC_DIR		=	$(BUILD_DIR)/src
BIN_DIR			=	bin
ARCH_BIN		=	$(BIN_DIR)/archives
ATT_DIR			=	Dependencies
INCLUDE_DIR		=	include

MLX_TARGET		=	libmlx.a
MLX_TARGET_PATH	=	$(MLX_PATH)/$(MLX_TARGET)
MLX_H_FILE		=	mlx.h
MLX_DIR			=	minilibx-linux
MLX_PATH		=	$(ATT_DIR)/$(MLX_DIR)
MLX_GIT			=	https://github.com/42Paris/minilibx-linux.git

LIBFT_TARGET	=	libft.a
LIBFT_DIR		=	Libft_Updated
LIBFT_H_FILE	=	libft.h
PRINTF_H_FILE	=	ft_printf.h
PRINTF_DIR		=	$(LIBFT_PATH)/src/ft_printf
LIBFT_PATH		=	$(ATT_DIR)/$(LIBFT_DIR)
LIBFT_GIT		=	https://github.com/Sellith/Libft_Updated.git

IFLAG			=	-I$(INCLUDE_DIR)
#---------------------------------------------------#
#                     ALL FILES                     #
#---------------------------------------------------#

ARCHIVES	=	$(ARCH_BIN)/libft.a $(ARCH_BIN)/printf.a $(ARCH_BIN)/libmlx.a

SRC			=	main.c map.c free.c parsing_utils.c display.c exit.c game.c \
				display_utils.c

OBJS_SRC	=	$(patsubst %.c, $(OBJ_SRC_DIR)/%.o, $(SRC))

all: $(TARGET)



$(TARGET): $(OBJS_SRC)
	@mkdir -p $(BIN_DIR)
	@$(MAKE) -C $(MLX_PATH) --no-print-directory > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_PATH) --no-print-directory
	@cp $(MLX_TARGET_PATH) $(ARCH_BIN)
	@printf "$(GRN)Info : MLX Compilation: Success !$(CRESET)\n"
	@if [ -f $(SRC_DIR)/$(TARGET_H_FILE) ]; then \
		mv $(SRC_DIR)/$(TARGET_H_FILE) $(INCLUDE_DIR);\
	fi
	@$(CC) $(OBJS_SRC) -o $@ $(IFLAG) $(ARCHIVES) $(MLXFLAGS)
	@printf "$(GRN)Info : Fichiers sources compilés !\n$(CRESET)"



$(OBJ_SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_SRC_DIR)
	@mkdir -p $(INCLUDE_DIR)
	@cp $(MLX_PATH)/$(MLX_H_FILE) $(INCLUDE_DIR)
	@cp $(LIBFT_PATH)/src/$(LIBFT_H_FILE) $(INCLUDE_DIR)
	@cp $(LIBFT_PATH)/src/get_next_line.h $(INCLUDE_DIR)
	@cp $(PRINTF_DIR)/$(PRINTF_H_FILE) $(INCLUDE_DIR)
	@$(CC) $(CFLAGS) -g $(IFLAG) -o $@ -c $<

clean:
	@rm -rf $(BUILD_DIR)
	@echo "$(GRN)Info : Object files deleted !$(CRESET)"

fclean: clean
	@rm -rf $(BIN_DIR)
	@echo "$(GRN)Info : Binaries deleted !$(CRESET)"


re: fclean all

.PHONY: all clean fclean re
