# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 15:58:15 by egache            #+#    #+#              #
#    Updated: 2025/03/07 18:15:51 by egache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBS		:=	gnl ft printf
LIBS_TARGET	:=				\
	get_next_line/libgnl.a	\
	libft/libft.a			\
	ft_printf/libprintf.a	\

HEAD		:=				\
include						\
get_next_line/include		\
libft/include				\
ft_printf/include			\

NAME	:=	push_swap

SRC_DIR	:=	src
SRC		:=					\
push_swap.c					\
parsing.c					\
check_arguments.c			\
stack_initialisation.c		\
operations_swap_push.c		\
operations_rotate.c			\
operations_reverse.c		\
sorting.c					\
free_exit.c					\
todump.c					\

SRC		:=	$(SRC:%=$(SRC_DIR)/%)

BUILD_DIR:=	.build
OBJ		:=	$(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP		:=	$(OBJ:%.o=.d)

AR	:=	ar -rcs

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
INCLUDE	:=	$(addprefix -I,$(HEAD)) -MMD -MP
LIBDIR	:=	$(addprefix -L,$(dir $(LIBS_TARGET)))
LIBNAME	:=	$(addprefix -l,$(LIBS))

DIR_DUP	=	mkdir -p $(@D)

MAKEFLAGS	+= --no-print-directory

RM	:=	rm -f
RMF	:=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(LIBS_TARGET)
			$(CC) $(LIBDIR) $(OBJ) $(LIBNAME) -o $(NAME)
			$(info $(NAME) DONE)

$(LIBS_TARGET)	:
			$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

-include $(DEP)

clean:
			$(RM) $(OBJ) $(DEP)
			$(RMF) $(BUILD_DIR)
			$(MAKE) clean -C get_next_line
			$(MAKE) clean -C libft
			$(MAKE) clean -C ft_printf

fclean:	clean
			$(RM) $(NAME)
			$(MAKE) fclean -C get_next_line
			$(MAKE) fclean -C libft
			$(MAKE) fclean -C ft_printf

re:
			$(MAKE) fclean
			$(MAKE) all

.PHONY:	all clean fclean re

.SILENT:
