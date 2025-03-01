# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 16:14:20 by procha-r          #+#    #+#              #
#    Updated: 2025/01/31 08:21:31 by procha-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
TEST_NAME = push_swap_tests
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRCS = \
	src/main.c \
	src/parse/parse_input.c \
	src/algo/small_sorts.c \
	src/algo/medium_sorts.c \
	src/algo/big_sorts.c \
	src/operations/ops_swap.c \
	src/operations/ops_push.c \
	src/operations/ops_rotate.c \
	src/operations/ops_reverse_rotate.c \
	src/stack/stack_init.c \
	src/stack/stack_utils.c \
	src/utils/sorting_helpers.c \
	src/utils/error_handling.c \
	src/utils/debug.c


TEST_SRC = \
tests/test_stack_init.c \
tests/test_error_handling.c \
tests/test_helpers.c \
tests/test_operations.c \
src/stack/stack_init.c \
src/utils/error_handling.c \
src/utils/debug.c

OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

test: $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) -o $(TEST_NAME)
	./$(TEST_NAME)

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test