/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:04:28 by teatime           #+#    #+#             */
/*   Updated: 2025/02/20 18:43:27 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		len;
}			t_stack;

typedef struct s_ps
{
	t_stack	*stack;
	char	**strs;
	int		strslen;
}			t_ps;

int			main(int argc, char **argv);

void		parsing(int argc, char **argv, t_ps *ps);
void		handle_single_argument(char *str, t_ps *ps);
void		handle_multiple_argument(int argc, char **argv, t_ps *ps);

void		check_arguments(int argc, char **argv, t_ps *ps);
int			invalid_argument(char *str);
int			empty_argument(char *str);
int			overflow_argument(char *str);
int			duplicate_argument(int argv, char **argc, int pos);

long		ft_atol_argument(char *str);
void		free_exit(t_ps *ps, char *str, int ret);

void		stack_initialisation(t_ps *ps, int len, char **tab);
int			stack_malloc(t_stack *stack, int len);
int			stack_fill(t_stack *stack, int len, char **tab);
void		ft_sort_int_tab(t_stack *stack, int len);
// void	struct_initialisation(t_ps *ps);

// void		stack_initialisation(int argc, char **argv, t_ps *ps);
// int			stack_malloc(int argc, char **argv, t_ps *ps);
// int			stack_copy(t_ps *ps);
#endif
