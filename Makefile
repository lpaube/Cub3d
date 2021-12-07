NAME =	cub3d

SRCS_DIR =	srcs
INCL_DIR =	includes
OBJ_DIR =	objs

SRCS =	main.c
OBJS =	$(SRCS:.c=.o)

SRCS_PATH = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS_PATH =	$(addprefix $(OBJ_DIR)/, $(OBJS))

CC =	gcc
CFLAGS =	-Wall -Wextra -Werror 
LIBS = -Lmlx_mac -lmlx
INCLS = -Iincludes -Imlx_mac

$(NAME): $(OBJ_DIR) $(OBJS_PATH)
	@echo "hello"
	$(CC) $(LIBS) $(OBJS_PATH) -o $(NAME)
	@echo "\\n\033[32;1m CUB3D HAS BEEN GENERATED \033[0m \\n"

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "test2"
	$(CC) $(CFLAGS) $(INCLS) -c $< -o $@
	@echo "Created: $@\033[1A\033[M"

all: $(NAME)

clean:
	rm -rf $(OBJS_PATH) $(OBJ_DIR)
	@echo "\033[34;1m CLEANED OBJECT FILES \033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[34;1m CLEANED CUB3D \033[0m"

re: fclean all

.PHONY: all clean fclean re
