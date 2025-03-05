/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:37:03 by teatime           #+#    #+#             */
/*   Updated: 2025/03/04 17:28:22 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arguments(t_ps *ps, char **args)
{
	int	i;

	i = 0;
	while (i < ps->stack->len)
	{
		if (empty_argument(args[i]) == 1)
			free_exit(ps, "Error\nEmpty argument", EXIT_FAILURE);
		if (invalid_argument(args[i]) == 1)
			free_exit(ps, "Error\nWrong arguments", EXIT_FAILURE);
		if (overflow_argument(args[i]) == 1)
			free_exit(ps, "Error\nArgument above limit", EXIT_FAILURE);
		if (duplicate_argument(ps->stack->len - 1, args, i) == 1)
			free_exit(ps, "Error\nDuplicate number", EXIT_FAILURE);
		i++;
	}
	return ;
}
void	handle_multiple_argument(int len, char **args, t_ps *ps)
{
	ps->stack->len = len;
	check_arguments(ps, args);
	stack_initialisation(ps, args);
}


void	handle_single_argument(char *arg, t_ps *ps)

{
	t_stack	*stack;

	stack = ps->stack;
	stack->len = 0;
	stack->args = ft_split(arg, ' ');
	if (stack->args == NULL)
		free_exit(ps, "Error\nMalloc failed", EXIT_FAILURE);
	while (stack->args[stack->len] != NULL)
		stack->len++;
	check_arguments(ps, stack->args);
	stack_initialisation(ps, stack->args);
}
