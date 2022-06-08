# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 19:19:45 by grenato-          #+#    #+#              #
#    Updated: 2022/06/07 21:32:56 by grenato-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# define the C compiler
CC = clang
#CC = gcc

# define any compile-time flags
CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -g -Wall -Wextra

# library flags
LDFLAGS = -g -L.

# name of the project
NAME = push_swap

B_NAME = checker

# name of include folder
INCLUDE = inc

INCLUDE_BONUS = inc_bonus

# name of source folder
SRC_DIR = src

BONUS_DIR = src_bonus
# name of libft folder
LIBFT_DIR = libft

UTILS_DIR = src/utils

LIBFT = libft/libft.a

HEADERS = -I/usr/include -I$(INCLUDE) -I$(LIBFT_DIR) -I$(INCLUDE_BONUS)

OBJ_DIR = obj
B_OBJ_DIR = obj_bonus

SOURCE_FILES = main.c receive_data.c node.c push.c swap.c rotate.c
SOURCE_FILES += reverse_rotate.c tree.c wheel_algorithm.c stack.c
SOURCE_FILES += instruction.c utils.c get_rotations.c sort_little.c

C_SOURCE = $(addprefix $(SRC_DIR)/, $(SOURCE_FILES))

BONUS_FILES = main.c receive_data_bonus.c node_bonus.c swap_bonus.c
BONUS_FILES += push_bonus.c reverse_rotate_bonus.c rotate_bonus.c
BONUS_FILES += execute_ps_instructions.c utils.c

B_SOURCE = $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))

OBJ = $(C_SOURCE:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
B_OBJ = $(B_SOURCE:$(BONUS_DIR)/%.c=$(B_OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(HEADERS) -O3 -c $< -o $@

$(B_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) $(HEADERS) -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(HEADERS) $(OBJ) -o $(NAME) $(LIBFT) $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(B_OBJ_DIR):
	mkdir -p $(B_OBJ_DIR)

bonus: $(B_OBJ_DIR) $(LIBFT) $(B_OBJ)
	$(CC) $(CFLAGS) $(HEADERS) $(B_OBJ) -o $(B_NAME) $(LIBFT) $(LDFLAGS)

clean:
	rm -rf $(OBJ)
	rm -rf $(B_OBJ)
	$(MAKE) -C ${LIBFT_DIR} clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(B_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all