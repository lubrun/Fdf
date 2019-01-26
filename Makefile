# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lubrun <lubrun@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/12/14 02:04:28 by lubrun       #+#   ##    ##    #+#        #
#    Updated: 2019/01/23 14:36:11 by lubrun      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

SRCS = 	srcs/fdf.c \
		srcs/parser.c \
		srcs/struct_utils.c \
		srcs/map_utils.c \
		srcs/utils.c \
		srcs/map_utils2.c \
		srcs/control.c \
		srcs/bonus.c \

OBJ = $(SRCS:%.c=%.o)

HEADER = includes

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

LIBMLX = minilibx_macos/libmlx.a 

OPENGL = -framework OpenGL -framework AppKit

all: $(NAME) 

$(NAME): $(LIBMLX) $(LIBFT) $(OBJ)
	gcc $(CFLAGS) $^ $(OPENGL) -o $@

$(LIBFT):
	make -C libft/

$(LIBMLX):
	make -C minilibx_macos/

clean:
	make clean -C libft/
	make clean -C minilibx_macos/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re:	fclean all
	make re -C minilibx_macos/

.PHONY: all clean fclean re
