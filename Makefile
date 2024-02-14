# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbelange <gbelange@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:06:22 by gbelange          #+#    #+#              #
#    Updated: 2024/02/06 21:34:31 by gbelange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CXX = @gcc
CFLAGS = -Wall -Wextra -Werror
RM = @rm -rf

GRAPHIC_LIBRARY = MLX42/build/libmlx42.a
MLX42_DIR = MLX42
MLX42_BUILD_DIR = $(MLX42_DIR)/build
MLX42_TARGET = $(MLX42_BUILD_DIR)/libmlx42.a
MLX42_CMAKE_ARGS = -B $(MLX42_BUILD_DIR)
MLX42_MAKE_COMMAND = make -C $(MLX42_BUILD_DIR) -j4

LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

INCLUDE = -I ./include/ -I ./libft/
DIR_SRCS = ./src/
DIR_OBJS = ./compiled_src/

SRC 	= 	main.c \
			parser/parsing.c \
			parser/parsing_color.c \
			parser/parsing_map.c \
			parser/parsing_map_2.c \
			parser/parsing_utils.c \
			utils/file_utils.c \
			init/initialization.c \
			init/initialization_2.c \
			error/error_management.c \
			input/callbacks.c \
			render/rendering.c \
			render/raycasting.c \
			render/raycastupdownleftright.c \
			render/raycastutils.c \
			maths/maths.c \
			movement/movement.c \
			movement/collision.c \

SRCS = $(SRC)
OBJS = $(SRCS:%.c=$(DIR_OBJS)%.o)

UNAME := $(shell uname -s)

ifeq ($(UNAME),Linux)
	DEPENDENCIES = $(MLX42_TARGET) -ldl -lglfw -pthread -lm
else ifeq ($(UNAME),Darwin)
	DEPENDENCIES = $(MLX42_TARGET) -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
endif

all: $(DIR_OBJS) $(LIBFT) $(MLX42_TARGET) $(NAME)

$(MLX42_TARGET):
	cmake $(MLX42_DIR) $(MLX42_CMAKE_ARGS)
	$(MLX42_MAKE_COMMAND)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@ $(INCLUDE) $(LIBFT) $(DEPENDENCIES)
	@echo "\033[35m$(NAME) compiled!\033[0m"

$(OBJS): | $(DIR_OBJS)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
	$(CXX) $(CFLAGS) -c $^ -o $@ $(INCLUDE)

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS)
	@mkdir -p $(DIR_OBJS)/init
	@mkdir -p $(DIR_OBJS)/parser
	@mkdir -p $(DIR_OBJS)/movement
	@mkdir -p $(DIR_OBJS)/render
	@mkdir -p $(DIR_OBJS)/error
	@mkdir -p $(DIR_OBJS)/exit
	@mkdir -p $(DIR_OBJS)/utils
	@mkdir -p $(DIR_OBJS)/input
	@mkdir -p $(DIR_OBJS)/maths

$(LIBFT):
	@make -sC $(LIBFT_PATH)

clean:
	$(RM) $(MLX42_BUILD_DIR) $(DIR_OBJS)
	@make -C $(LIBFT_PATH) fclean

fclean: clean
	$(RM) $(NAME)
	@if [ -d $(DIR_OBJS) ]; then rmdir $(DIR_OBJS); fi

re: fclean all

run: all
	./$(NAME) maps/test.cub $(filter-out $@,$(MAKECMDGOALS)) 

leaks: all
	leaks --atExit -- ./$(NAME) $(filter-out $@,$(MAKECMDGOALS))

.PHONY: clean all fclean re run leaks
