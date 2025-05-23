/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 00:21:18 by teatime           #+#    #+#             */
/*   Updated: 2025/03/07 17:50:27 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	int	swap;
	int	i;

	i = stack->len - 1;
	swap = 0;
	if (stack->b && stack->a && stack)
	{
		while (i > 0)
		{
			if (stack->a[i] != -1 && swap == 0)
				swap = stack->a[i];
			if (stack->a[i] != -1)
				stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = swap;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack *stack)
{
	int	swap;
	int	i;

	i = stack->len - 1;
	swap = 0;
	if (stack->b && stack->a && stack)
	{
		while (i > 0)
		{
			if (stack->b[i] != -1 && swap == 0)
				swap = stack->b[i];
			if (stack->b[i] != -1)
				stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = swap;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack *stack)
{
	int	swap;
	int	i;

	i = stack->len - 1;
	swap = 0;
	if (stack->b && stack->a && stack)
	{
		while (i > 0)
		{
			if (stack->a[i] != -1 && swap == 0)
				swap = stack->a[i];
			if (stack->a[i] != -1)
				stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = swap;
		write(1, "rrr\n", 4);
	}
}
