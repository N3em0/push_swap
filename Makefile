# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 15:58:15 by egache            #+#    #+#              #
#    Updated: 2025/04/11 15:30:48 by egache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBS		:=	ft
LIBS_TARGET	:=					\
	libft/libft.a				\

HEADER := include/push_swap.h	\

HEAD		:=					\
include							\
libft/include					\

NAME	:=	push_swap

SRC_DIR	:=	src
SRC		:=						\
push_swap.c						\
parsing.c						\
check_arguments.c				\
stack_initialisation.c			\
operations_swap_push.c			\
operations_rotate.c				\
operations_reverse.c			\
sorting.c						\
free_exit.c						\
push_swap_utils.c				\

SRC		:=	$(SRC:%=$(SRC_DIR)/%)


BUILD_DIR:=	.build
OBJ		:=	$(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP		:=	$(OBJ:%.o=.d)

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
INCLUDE	:=	$(addprefix -I,$(HEAD)) -MMD -MP
LIBDIR	:=	$(addprefix -L,$(dir $(LIBS_TARGET)))
LIBNAME	:=	$(addprefix -l,$(LIBS))

DIR_DUP	=	mkdir -p $(@D)

MAKEFLAGS	+= --no-print-directory

RM	:=	rm -f
RMF	:=	rm -rf

BOLDGREEN	:= \e[1;32m
BOLDBLUE 	:= \033[1;34m
YELLOW		:= \033[1;93m
WHITE 		:= \033[0m
BLUE		:= \033[0;34m
PURPLE		:= \e[1;35m

all:		.printsep $(NAME)
			echo "$(BOLDBLUE)$(NAME) $(WHITE)compilation $(BOLDGREEN)done"
			$(call SEPARATOR)

$(NAME)	:	$(OBJ) $(LIBS_TARGET) $(HEADER)
			$(CC) $(LIBDIR) $(OBJ) $(LIBNAME) -o $(NAME)
			$(call SEPARATOR)
			echo "$(BOLDBLUE)$(NAME) $(WHITE)compilation  $(YELLOW)..."
			$(call SEPARATOR)

$(LIBS_TARGET)	: FORCE
			$(MAKE) -C $(@D)
			@echo "$(BOLDBLUE)$(@D) $(WHITE)library $(BOLDGREEN)done"

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<


-include $(DEP)

clean:
			$(RM) $(OBJ) $(DEP)
			$(RMF) $(BUILD_DIR)
			$(MAKE) clean -C libft

fclean:	clean
			$(call SEPARATOR)
			echo "$(BOLDBLUE)$(NAME) $(WHITE)fclean  $(YELLOW)..."
			$(RM) $(NAME)
			$(MAKE) fclean -C libft
			$(call SEPARATOR)
			echo "$(BOLDBLUE)$(NAME) $(WHITE)fclean  $(BOLDGREEN)done"

re:
			$(MAKE) fclean
			$(MAKE) all

.printsep:
			$(call SEPARATOR)

FORCE :

.PHONY:	all clean fclean FORCE re

.SILENT:

define	SEPARATOR
						@echo "\n$(PURPLE)--------------------------\n";
endef
