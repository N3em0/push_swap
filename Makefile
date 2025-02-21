# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teatime <teatime@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 15:58:15 by egache            #+#    #+#              #
#    Updated: 2025/02/22 00:30:51 by teatime          ###   ########.fr        #
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
check_argument.c			\
stack_initialisation.c		\
free_exit.c					\
operations_swap_push.c		\
operations_rotate.c			\
operations_reverse.c		\
todump.c					\

SRC		:=	$(SRC:%=$(SRC_DIR)/%)

BUILD_DIR:=	.build
OBJ		:=	$(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP		:=	$(OBJ:%.o=.d)

AR	:=	ar -rcs

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror -g3
INCLUDE	:=	$(addprefix -I,$(HEAD)) -MMD -MP
LIBDIR	:=	$(addprefix -L,$(dir $(LIBS_TARGET)))
LIBNAME	:=	$(addprefix -l,$(LIBS))

DIR_DUP	=	mkdir -p $(@D)

RM	:=	rm -f
RMF	:=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(LIBS_TARGET)
			$(CC) $(LIBDIR) $(OBJ) $(LIBNAME)
			#$(info CREATED $(NAME))

$(LIBS_TARGET)	:
			@$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(info INCLUDE paths: $(INCLUDE)) $(INCLUDE) -c -o $@ $<
			$(info CREATED $@)

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
			#$(info CLEANED $(NAME))

re:
			$(MAKE) fclean
			$(MAKE) all

.PHONY:	all clean fclean re

.SILENT:
