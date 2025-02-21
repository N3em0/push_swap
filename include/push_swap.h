/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:04:28 by teatime           #+#    #+#             */
/*   Updated: 2025/02/21 20:20:36 by egache           ###   ########.fr       */
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
	char	**args;
	int		len;
	int		*a;
	int		*b;
	int		*indexed;
	int		*presort;
	int		*saved;
}			t_stack;

typedef struct s_ps
{
	t_stack	*stack;
}			t_ps;

int			main(int argc, char **argv);

void		parsing(int argc, char **argv, t_ps *ps);
void		handle_single_argument(char *arg, t_ps *ps);
void		handle_multiple_argument(int len, char **args, t_ps *ps);

void		check_arguments(t_ps *ps, char **args);
int			invalid_argument(char *arg);
int			empty_argument(char *arg);
int			overflow_argument(char *arg);
int			duplicate_argument(int len, char **args, int pos);

long		ft_atol_argument(char *str);
void		free_exit(t_ps *ps, char *str, int ret);

void		stack_initialisation(t_ps *ps, char **args);
int			stack_malloc(t_stack *stack, int len);
int			stack_fill(t_stack *stack, int len, char **tab);
int			stack_indexing(t_stack *stack);
void		ft_sort_int_tab(t_stack *stack, int len);

void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);
void		pa(t_stack *stack);
void		pb(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);
// void		rra(t_stack *stack);
// void		rrb(t_stack *stack);
// void		rrr(t_stack *stack);

// void	struct_initialisation(t_ps *ps);

// void		stack_initialisation(int argc, char **argv, t_ps *ps);
// int			stack_malloc(int argc, char **argv, t_ps *ps);
// int			stack_copy(t_ps *ps);
#endif
