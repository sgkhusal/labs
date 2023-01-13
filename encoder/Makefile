# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 10:09:19 by sguilher          #+#    #+#              #
#    Updated: 2023/01/13 19:29:14 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		encoder.bin

# INPUTS

SRCS =		main.c encoder.c $(HUFFMAN) $(UTILS) $(SHMEM)
HUFFMAN =	frequency.c list.c tree.c dictionary.c encode.c compress.c
SHMEM =		shared_memory.c
UTILS =		error.c
OBJS_DIR =	./obj
OBJS	=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

HEADERS	=	encoder.h huffman.h utils.h shared_memory.h
VPATH	=	../huffman ../utils ../shared_memory
INCLUDE	=	-I./ -I../utils -I../huffman -I../shared_memory

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
	@echo "$(YELLOW)encoder.bin created$(RESET)"
	@echo "------------------------------------------------------------------"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
		$(RM_DIR) $(OBJS_DIR)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
