/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:45:55 by egache            #+#    #+#             */
/*   Updated: 2025/03/26 18:34:56 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	swap;

	if (stack->b && stack->a && stack)
	{
		swap = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = swap;
		write(1, "sa\n", 3);
	}
	return ;
}

void	sb(t_stack *stack)
{
	int	swap;

	if (stack->b && stack->a && stack)
	{
		swap = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = swap;
		write(1, "sb\n", 3);
	}
	return ;
}

void	ss(t_stack *stack)
{
	int	swap;

	if (stack->b && stack->a && stack)
	{
		swap = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = swap;
		swap = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = swap;
		write(1, "ss\n", 3);
	}
	return ;
}

void	pa(t_stack *stack)
{
	int	i;

	if (stack->b && stack->a && stack)
	{
		i = stack->len - 1;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = stack->b[0];
		i = 0;
		while (i < stack->len - 1 && stack->b[i] != -1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[stack->len - 1] = -1;
		write(1, "pa\n", 3);
	}
	return ;
}

void	pb(t_stack *stack)
{
	int	i;

	if (stack->b && stack->a && stack)
	{
		i = stack->len - 1;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = stack->a[0];
		i = 0;
		while (i < stack->len - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a[stack->len - 1] = -1;
		write(1, "pb\n", 3);
	}
	return ;
}
