# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 10:09:19 by sguilher          #+#    #+#              #
#    Updated: 2023/01/15 01:47:47 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				cmpanalyzer
ENCODER =			./encoder/encoder
DECODER =			./decoder/decoder
ENCODER_PATH =		./encoder
DECODER_PATH =		./decoder
UNIT_TESTS_PATH =	./unit_tests

# INPUTS

SRCS =			cmpanalyzer.c executers.c error.c texts.c
OBJS_DIR =		./obj
OBJS	=		$(SRCS:%.c=$(OBJS_DIR)/%.o)

HEADERS	=		cmpanalyzer.h utils.h
VPATH	=		src utils
INCLUDE	=		-I./ -I./includes -I./utils -I./encoder

# compilation
CC =		gcc
CFLAGS =	-Wall -Werror -Wextra -g

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

$(NAME):	$(ENCODER) $(DECODER) $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	@echo "$(GREEN)"
	@echo "************************************"
	@echo "        cmpanalyzer created"
	@echo "************************************"
	@echo "$(RESET)"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(ENCODER):
	$(MAKE) --no-print-directory -C $(ENCODER_PATH)

$(DECODER):
	$(MAKE) --no-print-directory -C $(DECODER_PATH)

test:
		@$(MAKE) --no-print-directory -C ./unit_tests test

clean:
		$(RM_DIR) $(OBJS_DIR)
		@$(MAKE) --no-print-directory -C $(ENCODER_PATH) clean

fclean:		clean
		$(RM) $(NAME)
		@$(MAKE) --no-print-directory -C $(ENCODER_PATH) fclean
		@$(MAKE) --no-print-directory -C $(DECODER_PATH) fclean
		@$(MAKE) --no-print-directory -C $(UNIT_TESTS_PATH) fclean

re:			fclean all

.PHONY: all clean fclean re tests
