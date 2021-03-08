# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esukava <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/10 12:13:28 by esukava           #+#    #+#              #
#    Updated: 2021/03/04 15:43:26 by alero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC_LIST = main.c \
	barsleyfern.c \
	check_arg.c \
	draw_pixel.c \
	image_builder.c \
	img_init.c \
	julia_point.c \
	key_callback.c \
	loop_callback.c \
	mndlslw_point.c \
	mouse_callback.c \
	printer_arm.c
INCLUDE_DIR = inc
SRC_DIR = src
LDFLAGS = -LLibft -lft -Lminilibx-linux-master -lmlx -lXext -lX11
BUILD_DIR = build
LIBFT = Libft/libft.a
LIBMLX = minilibx-linux-master/libmlx.a
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)
RM = rm -f
SRC = $(addprefix $(SRC_DIR)/, $(SRC_LIST))
OBJ = $(addprefix $(BUILD_DIR)/, $(SRC_LIST:.c=.o))
INCLUDES = inc

all : $(NAME)

$(LIBFT) :
	make --directory=Libft

$(LIBMLX) :
	make --directory=minilibx-linux-master

$(NAME) :	$(OBJ) $(LIBFT) $(LIBMLX)
	gcc $(OBJ) $(LDFLAGS) -o $(NAME)

$(BUILD_DIR) :
	mkdir build

#
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/fractol.h | $(BUILD_DIR)
	gcc $(CFLAGS) -c $< -o $@

debug : CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror -I $(INCLUDE_DIR)
debug : LDFLAGS = -LLibft -lft -Lminilibx-linux-master -lmlx -lXext -lX11 -fsanitize=address
debug : all

clean :
	rm -R -f $(BUILD_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re debug
