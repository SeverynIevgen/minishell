# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 14:39:33 by zdawnsta          #+#    #+#              #
#    Updated: 2020/11/05 14:39:45 by zdawnsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
TEST = test

SRCS = 	main.c \
		envv_init.c \
		cmd_pwd.c \
		cmd_cd.c \
		cmd_echo.c \
		cmd_env.c \
		cmd_unset.c

HEADER = include/minishell.h
OBJS = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a
RM = rm -f
RMR = rm -rf

all: $(TEST)

%.o: %.c $(HEADER) $(LIB)
	$(CC) $(FLAGS) -c $< -o $@

$(TEST): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIB) -o $(TEST)

clean:
	@echo "\033[0;31mCleaning..."
	$(RMR) $(OBJS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mRemoving executable..."
	$(RM) $(TEST)
	@echo "\033[0m"

re: fclean all

.PHONY: all clean fclean re test
