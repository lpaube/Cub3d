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

#Compiling for Linux
ifeq ($(shell uname), Linux)
$(NAME): $(OBJ_DIR) $(OBJS_PATH)
	@echo "\n\tCOMPILING FOR LINUX\n======================================="
	@make re --no-print-directory -C ./libft
	$(CC) $(CFLAGS) srcs/*.c -Imlx_linux -Iincludes -Lmlx_linux -Llibft -lft -lmlx -lX11 -lm -lz -lXext -o $(NAME)

#Compiling for MacOS
else
$(NAME): $(OBJ_DIR) $(OBJS_PATH)
	@echo "\n\tCOMPILING FOR MAC_OS\n======================================="
	@make re --no-print-directory -C ./libft
	$(CC) $(LIBS) $(OBJS_PATH) -o $(NAME)
	@echo "\\n\033[32;1m CUB3D HAS BEEN GENERATED \033[0m \\n"
endif

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

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


.PHONY: all clean fclean re
