# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 14:02:25 by mafortin          #+#    #+#              #
#    Updated: 2021/11/14 18:52:00 by mafortin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

OBJS_DIR	= objs/

SRCS_FILES 	= 	ft_isalnum.c ft_isdigit.c ft_memccpy.c ft_memcpy.c ft_putchar_fd.c\
				ft_putstr_fd.c ft_strdup.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c\
				ft_toupper.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memchr.c\
				ft_memmove.c ft_putendl_fd.c ft_split.c ft_strjoin.c ft_strlen.c\
				ft_strnstr.c ft_substr.c ft_atoi.c ft_calloc.c ft_isascii.c ft_itoa.c\
				ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strlcat.c\
				ft_strmapi.c ft_strrchr.c ft_tolower.c ft_digit_len.c ft_utoa.c\
				ft_inv_string.c ft_itoa_hex.c ft_free_tab.c ft_lstnew.c ft_lstadd_front.c\
				ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c\
				ft_lstiter.c ft_lstmap.c ft_lst_return_int.c ft_atol.c ft_lstnew.c \
				ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_matrice_size.c ft_isdigit_s.c\
				ft_isdigit_string.c get_next_line.c get_next_line_utils.c ft_char_search.c\
				ft_change_line.c ft_print_matrice.c ft_matrice_cpy.c ft_addline.c\
				ft_print_matrice_fd.c ft_majchar.c ft_strndup.c ft_remove_line.c\
				ft_append_string.c ft_sort_strtab.c ft_strcmp.c ft_trim_string.c\
				ft_nbline_fd.c


OBJS_FILES	= $(SRCS_FILES:.c=.o)

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS		= $(addprefix $(OBJS_DIR), $(OBJS_FILES))
VPATH		= $(SRCS_DIR)


HEADER	= libft.h


all: 		obj ${NAME}

$(NAME): $(OBJS)
			@ar rc ${NAME} $(OBJS)

$(OBJS_DIR)%.o:%.c
	@$(CC) $(CFLAGS) -o $@ -c $< 

bonus:		${OBJS} ${OBJS_B}
			@ar rc ${NAME} ${OBJS} ${OBJS_B}

obj:
	@mkdir -p $(OBJS_DIR)

clean:
					rm -rf ${OBJS}

fclean: 	clean
					rm -rf $(NAME) $(OBJS_DIR)

re:			fclean all

.PHONY: all clean fclean re bonus
