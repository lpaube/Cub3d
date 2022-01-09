NAME =	cub3d

SRCS_DIR =	srcs
INCL_DIR =	includes
OBJ_DIR =	objs

SRCS =	main.c context_2d.c
OBJS =	$(SRCS:.c=.o)

SRCS_PATH = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS_PATH =	$(addprefix $(OBJ_DIR)/, $(OBJS))

CC =	gcc
CFLAGS =	-Wall -Wextra -Werror -g
INCLS = -Iincludes -Imlx_mac
LIBS = -Lmlx_mac -lmlx -Llibft -lft -framework OpenGL -framework AppKit

#Compiling for Linux
ifeq ($(shell uname), Linux)
$(NAME): $(OBJ_DIR) $(OBJS_PATH)
	@echo "\n\tCOMPILING FOR LINUX\n======================================="
	@make re --no-print-directory -C ./libft
	@echo "- Compiled libft"
	@make re --no-print-directory -C ./mlx_linux
	@echo "- Compiled mlx_linux"
	@$(CC) $(CFLAGS) -D _LINUX=yes srcs/*.c -Imlx_linux -Iincludes -Lmlx_linux -Llibft -lft -lmlx -lX11 -lm -lz -lXext -o $(NAME)
	@echo "- Compiled Cub3d obj files"
	@echo "\\n\033[32;1m CUB3D HAS BEEN GENERATED \033[0m \\n"

#Compiling for MacOS
else
$(NAME): $(OBJ_DIR) $(OBJS_PATH)
	@echo "\n\tCOMPILING FOR MAC_OS\n======================================="
	@make re --no-print-directory -C ./libft
	@$(CC) $(LIBS) $(OBJS_PATH) -o $(NAME)
	@echo "\\n\033[32;1m CUB3D HAS BEEN GENERATED \033[0m \\n"
endif

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLS) -c $< -o $@

all: $(NAME)

clean:
	@echo "\n\tCLEANING\n======================================="
	@make clean --no-print-directory -C ./libft
	@echo "- Removed libft obj files"
	@rm -rf $(OBJS_PATH) $(OBJ_DIR)
	@echo "- Removed Cub3d obj files"

fclean: clean
	@echo "\n\tCLEANING BINARIES\n======================================="
	@make fclean --no-print-directory -C ./libft
	@echo "- Removed libft lib file"
	@rm -f $(NAME)
	@echo "- Removed Cub3d bin file"
	@echo "\\n\033[34;1m CUB3D HAS BEEN CLEANED \033[0m \\n"

re: fclean all

#######################################


.PHONY: all clean fclean re compiled
