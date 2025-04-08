# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 15:12:53 by daeunki2          #+#    #+#              #
#    Updated: 2025/04/08 14:18:37 by daeunki2         ###   ########.fr        #
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
CFLAGS = -Wextra -Werror -Wall

# Adding builtins directory path
SRCS_DIRECTORY = ./sources/
OBJ_DIR = ./obj/

SRCS = 	$(SRCS_DIRECTORY)main.c \
		$(SRCS_DIRECTORY)check_clean.c \
		$(SRCS_DIRECTORY)init_table.c \
		$(SRCS_DIRECTORY)parsing.c \
		$(SRCS_DIRECTORY)printer.c \
		$(SRCS_DIRECTORY)utils.c \
		$(SRCS_DIRECTORY)philo_routin.c \

OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lpthread
	@echo "$(BOLD_CYAN)               philo is ready!$(RESET)"
	@echo "$(BOLD_GREEN)*-----------------------------------------*$(RESET)"
	@echo "$(BOLD_GREEN)|For usage : $(BOLD_RED)./philo num num num num (num)$(BOLD_GREEN)| $(RESET) $(RESET) $(RESET)"
	@echo "$(BOLD_GREEN)*-----------------------------------------*$(RESET)"
	
all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(BOLD_RED)Cleaning philo object files..$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(BOLD_RED)Cleaning philo exec files..$(RESET)"
	@echo "$(BOLD_GREEN)Everything is cleaned!!$(RESET)"
	
re: fclean all

norm:
	@echo "$(BOLD_BLUE)Checking norminette for C files...$(RESET)"
	@norminette $(SRCS) \
	|| { echo "$(RED)Norminette failed :( $(RESET)"; exit 1; }
	@echo "$(BLUE)Checking norminette for Include...$(RESET)"
	@norminette ./include/philo.h || { echo "$(BOLD_RED)Norminette failed for header$(RESET)"; exit 1; }
	@echo "$(BOLD_GREEN)No norm error :) !$(RESET)"

.PHONY: all clean fclean re norm