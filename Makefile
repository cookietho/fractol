# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minakim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/16 18:25:04 by minakim           #+#    #+#              #
#    Updated: 2019/02/19 15:35:50 by minakim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
NAME = fractol
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

SRC = main.c\
	  init.c\
	  render.c\
	  color.c\
	  tools.c\
	  mouse.c\
	  mandelbroth.c\
	  julia.c\
	  burning.c\
	  special1.c\
	  special2.c

OBJ = $(SRC:.c=.o)
MLX = -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

LIB_DIR = lib/libft
MLX_DIR = lib/minilibx_macos
SRC_DIR = srcs
OBJ_DIR = objs

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))
LIBS = -L $(LIB_DIR) -lft
HEADER = -I /includes -I $(LIB_DIR)/includes -I $(MLX_DIR)

all: $(NAME)

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	@mkdir -p $(OBJ_DIR)
# 	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(NAME): 
	#$(OBJS)
	$(MAKE) $(MLX_DIR)
	$(MAKE) $(LIB_DIR)
	$(CC) $(CFLAGS) -I. -I $(MLX_DIR) -I $(LIB_DIR) -c $(SRCS)
	$(CC) $(CFLAGS) $(LIBS) $(MLX) $(OBJ) -o $(NAME)
	@mkdir $(OBJ_DIR)
	@mv *.o $(OBJ_DIR)
	@echo "File \"fractol\" Created\n"

clean:
	@/bin/rm -rf $(OBJ_DIR)
	$(MAKE) $(MLX_DIR) clean
	$(MAKE) $(LIB_DIR) clean
	@echo "Object File Removed\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@rm -f $(LIB_DIR)/libft.a
	@echo "Removed executable & .o files\n"

re: fclean all

.PHONY: all, clean, fclean, re
.SUFFIXES: .c .o
