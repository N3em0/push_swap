# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teatime <teatime@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 14:29:30 by egache            #+#    #+#              #
#    Updated: 2025/02/14 16:27:34 by teatime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD			:=	get_next_line.h

NAME			:=	libgnl.a

SRC_DIR			:=	src
SRC				:=				\
	get_next_line.c				\
	get_next_line_utils.c		\

SRC				:=	$(SRC:%=$(SRC_DIR)/%)

BUILD_DIR		:=	.build
OBJ				:=	$(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP				:=	$(OBJ:%.o=.d)

AR				:=	ar -rcs

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror -g3
INCLUDE			:=	-MMD -MP -Iinclude

MAKEFLAGS		+=	--no-print-directory

DIR_DUP			=	mkdir -p $(@D)

RM				:=	rm -f
RMF				:=	rm -rf

all				:	$(NAME)

$(NAME)			:	$(OBJ)
			$(AR) $(NAME) $(OBJ)
			$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<
			$(info CREATED $@)

-include	$(DEP)

clean 			:
			$(RMF) $(BUILD_DIR)

fclean			:	clean
			$(RM) $(NAME)

re				:
			$(MAKE) fclean
			$(MAKE) all

.PHONY			:	all clean fclean re

.SILENT			:
