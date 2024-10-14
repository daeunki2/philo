# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 15:12:53 by daeunki2          #+#    #+#              #
#    Updated: 2024/10/14 14:02:23 by daeunki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Text colors
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

# Bold text colors
BOLD_BLACK = \033[1;30m
BOLD_RED = \033[1;31m
BOLD_GREEN = \033[1;32m
BOLD_YELLOW = \033[1;33m
BOLD_BLUE = \033[1;34m
BOLD_MAGENTA = \033[1;35m
BOLD_CYAN = \033[1;36m
BOLD_WHITE = \033[1;37m

# Reset color
RESET = \033[0m

# Principals variable needed
NAME = philo
CC = gcc

# Adding libft directory
LIBFT_DIR = ./include/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Adding builtins directory path
BUILTINS_DIRECTORY = builtins/
SRCS_DIRECTORY = ./sources/
OBJ_DIR = ./obj/

SRCS = 	$(SRCS_DIRECTORY)main.c \
		$(SRCS_DIRECTORY)parsing.c \
		
OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)
LIBS = -lreadline

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB) $(LIBS)
	@echo "$(BOLD_GREEN)philo is ready!$(RESET)"
	@echo "$(BOLD_GREEN)-------------------$(RESET)"
	@echo "$(BOLD_GREEN)For usage : $(RED)./philo$(RESET) $(RESET)"

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR) -s

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean -s
	@echo "$(BOLD_YELLOW)Cleaning libft object file..$(RESET)"
	@echo "$(BOLD_YELLOW)Cleaning philo object file..$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean -s
	@echo "$(BOLD_RED)Cleaning philo exec file..$(RESET)"
	@echo "$(BOLD_GREEN)Everything is cleaned !$(RESET)"
	
re: fclean all

norm:
	@echo "$(BLUE)Checking norminette for C files...$(RESET)"
	@norminette $(SRCS) \
	|| { echo "$(RED)Norminette failed :( $(RESET)"; exit 1; }
	@echo "$(BLUE)Checking norminette for Include...$(RESET)"
	@norminette ./include/philo.h || { echo "$(RED)Norminette failed for header$(RESET)"; exit 1; }
	@echo "$(GREEN)Norm is all good!$(RESET)"

.PHONY: all clean fclean re norm