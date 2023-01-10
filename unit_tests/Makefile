# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 10:15:28 by sguilher          #+#    #+#              #
#    Updated: 2023/01/10 10:44:46 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			unit_test

# INPUTS

SRCS =			main.c \
				frequency_test.c \
				$(FUNCTIONS_SRCS)
FUNCTIONS_SRCS = frequency.c

OBJS_DIR =		./obj
OBJS	=		$(SRCS:%.c=$(OBJS_DIR)/%.o)

HEADERS	=		unit_tests.h

VPATH_FUNCTIONS =	../huffman
VPATH	=		$(VPATH_FUNCTIONS) huffman
INCLUDE	=		-I ./ -I ../huffman

# compilation
CC =		gcc
CFLAGS =	-Werror -Wextra -g

# clean
RM =		-rm -f
RM_DIR =	rm -rf

# colors
YELLOW	=	\033[1;33m
GREEN	=	\033[1;32m
RESET	=	\033[0m

# **************************************************************************** #
# rules

all:	$(NAME)

$(OBJS_DIR)/%.o:	%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME):	$(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	@echo "$(GREEN)"
	@echo "************************************"
	@echo "         unit_tests created"
	@echo "************************************"
	@echo "$(RESET)"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

test:		$(NAME)
		./$(NAME)

clean:
		$(RM_DIR) $(OBJS_DIR)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re test
