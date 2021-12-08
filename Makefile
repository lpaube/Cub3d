NAME =	cub3d

SRCS_DIR =	srcs
INCL_DIR =	includes
OBJ_DIR =	objs

SRCS =	main.c
OBJS =	$(SRCS:.c=.o)

SRCS_PATH = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS_PATH =	$(addprefix $(OBJ_DIR)/, $(OBJS))

CC =	gcc
CFLAGS =	-Wall -Wextra -Werror -g
INCLS = -Iincludes -Imlx_mac
LIBS = -Lmlx_mac -lmlx -Llibft -lft -framework OpenGL -framework AppKit

$(NAME): $(OBJ_DIR) $(OBJS_PATH)
	@make re --no-print-directory -C ./libft
	$(CC) $(LIBS) $(OBJS_PATH) -o $(NAME)
	@echo "\\n\033[32;1m CUB3D HAS BEEN GENERATED \033[0m \\n"

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLS) -c $< -o $@
	@echo "Created: $@\033[1A\033[M"

all: $(NAME)

clean:
	@make clean --no-print-directory -C ./libft
	rm -rf $(OBJS_PATH) $(OBJ_DIR)
	@echo "\033[34;1m CLEANED OBJECT FILES \033[0m"

fclean: clean
	@make fclean --no-print-directory -C ./libft
	rm -f $(NAME)
	@echo "\033[34;1m CLEANED CUB3D \033[0m"

re: fclean all

#######################################

linux: $(OBJ_DIR) $(OBJS_PATH)
	@make re --no-print-directory -C ./libft
	$(CC) $(CFLAGS) srcs/*.c -Imlx_linux -Lmlx_linux -Llibft -lft -lmlx -lX11 -lm -lz -lXext -o $(NAME)

.PHONY: all clean fclean re
