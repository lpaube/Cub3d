NAME =	cub3d

SRCS_DIR =		srcs
PARSING_DIR =	srcs/parsing
GRAPHICS_DIR =	srcs/graphics
INCL_DIR =		includes
OBJ_DIR =		objs

SRCS =	main.c game_context.c draw_map.c\
			draw_raycasting.c draw_utils.c init_2d.c\
			player_mvmt.c raycasting.c show_3d.c user_input.c

PARSING =	cb_parsing.c cb_map.c cb_parsing_utils.c\
			cb_map_utils.c cb_texture.c cb_color.c  cb_valid_map.c

GRAPHICS = background.c

OBJS =	$(SRCS:.c=.o) $(PARSING:.c=.o) $(GRAPHICS:.c=.o)

SRCS_PATH = $(addprefix $(SRCS_DIR)/, $(SRCS))
PARSING_PATH = $(addprefix $(PARSING_DIR)/, $(PARSING))
GRAPHICS_PATH = $(addprefix $(GRAPHICS_DIR)/, $(GRAPHICS))
OBJS_PATH =	$(addprefix $(OBJ_DIR)/, $(OBJS))

CC =	gcc
CFLAGS =	-Wall -Wextra -Werror -g
INCLS = -Iincludes -Imlx_mac
LIBS = -Lmlx_mac -lmlx -Llibft -lft -framework OpenGL -framework AppKit

VPATH = $(SRCS_DIR) $(PARSING_DIR) $(GRAPHICS_DIR)

#Compiling for Linux
ifeq ($(shell uname), Linux)
$(NAME): $(OBJ_DIR) $(OBJS_PATH)
	@echo "\n\tCOMPILING FOR LINUX\n======================================="
	@make re --no-print-directory -C ./libft
	@echo "- Compiled libft"
	@make re --no-print-directory -C ./mlx_linux
	@echo "- Compiled mlx_linux"
	@$(CC) $(CFLAGS) -D _LINUX=yes srcs/*.c srcs/parsing/*.c -Imlx_linux -Iincludes -Lmlx_linux -Llibft -lft -lmlx -lX11 -lm -lz -lXext -o $(NAME)
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

$(OBJ_DIR)/%.o: %.c
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
