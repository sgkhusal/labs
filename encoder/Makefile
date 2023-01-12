# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 10:09:19 by sguilher          #+#    #+#              #
#    Updated: 2023/01/12 12:50:16 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		encoder.out

# INPUTS

SRCS =		main.c $(HUFFMAN)
HUFFMAN =	huffman_coding.c frequency.c list.c utils.c tree.c \
			dictionary.c encode.c decode.c compress.c
OBJS_DIR =	./obj
OBJS	=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

HEADERS	=	huffman.h
VPATH	=	../huffman
INCLUDE	=	-I./ -I../includes -I../huffman

# compilation
CC =		gcc
CFLAGS =	-Wall -Werror -Wextra -g
MATH =		-lm

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
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MATH)
	@echo "$(GREEN)"
	@echo "$(YELLOW)encoder.out created$(RESET)"
	@echo "------------------------------------------------------------------"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
		$(RM_DIR) $(OBJS_DIR)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re tests
