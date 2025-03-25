/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:13:23 by teatime           #+#    #+#             */
/*   Updated: 2025/03/25 15:19:34 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		free_exit(stack, "Error\n", EXIT_FAILURE);
	parsing(argc, argv, stack);
	sorting(stack);
	free_exit(stack, NULL, EXIT_SUCCESS);
	return (0);
}

void	parsing(int argc, char **argv, t_stack *stack)
{
	if (argc < 2)
		free_exit(stack, NULL, EXIT_FAILURE);
	else if (argc == 2)
		handle_single_argument(argv[1], stack);
	else
		handle_multiple_argument(argc - 1, argv + 1, stack);
}

void	sorting(t_stack *stack)
{
	if (stack_sorted(stack) == 0 || stack->len == 1)
		free_exit(stack, NULL, EXIT_SUCCESS);
	else if (stack->len == 2)
		sa(stack);
	else if (stack->len == 3)
		three_sorting(stack, 0, 2);
	else if (stack->len == 4)
		four_sorting(stack);
	else if (stack->len == 5)
		five_sorting(stack);
	else
		radix_sorting(stack);
}
