/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:45:55 by egache            #+#    #+#             */
/*   Updated: 2025/03/05 18:02:03 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	swap;

	if (stack->a[0] != -1 && stack->a[1] != -1)
	{
		swap = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = swap;
	}
	return ;
}
void	sb(t_stack *stack)
{
	int	swap;

	if (stack->b[0] != -1 && stack->b[1] != -1)
	{
		swap = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = swap;
	}
	return ;
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}

void	pa(t_stack *stack)
{
	int	i;

	if (stack->b[0] != -1)
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
	}
}
void	pb(t_stack *stack)
{
	int	i;

	if (stack->a[0] != -1)
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
	}
}
