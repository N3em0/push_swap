/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:37:03 by teatime           #+#    #+#             */
/*   Updated: 2025/04/11 13:30:49 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arguments(t_stack *stack, char **args)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (empty_argument(args[i]) == 1)
			free_exit(stack, "Error\n", EXIT_FAILURE);
		if (invalid_argument(args[i]) == 1)
			free_exit(stack, "Error\n", EXIT_FAILURE);
		if (overflow_argument(args[i]) == 1)
			free_exit(stack, "Error\n", EXIT_FAILURE);
		if (duplicate_argument(stack->len - 1, args, i) == 1)
			free_exit(stack, "Error\n", EXIT_FAILURE);
		i++;
	}
	return ;
}

void	handle_multiple_argument(int len, char **args, t_stack *stack)
{
	stack->len = len;
	check_arguments(stack, args);
	stack_initialisation(stack, args);
}

void	handle_single_argument(char *arg, t_stack *stack)

{
	stack->len = 0;
	stack->args = ft_split(arg, ' ');
	if (stack->args == NULL)
		free_exit(stack, "Error\n", EXIT_FAILURE);
	while (stack->args[stack->len] != NULL)
		stack->len++;
	check_arguments(stack, stack->args);
	stack_initialisation(stack, stack->args);
}
