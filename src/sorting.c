/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:57:46 by egache            #+#    #+#             */
/*   Updated: 2025/04/02 18:26:49 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len - 1 && stack->a[i + 1] != -1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	three_sorting(t_stack *stack, int min, int max)
{
	if ((stack->a[0] == max && stack->a[2] == min) || (stack->a[0] == min
			&& stack->a[1] == max) || (stack->a[1] == min
			&& stack->a[2] == max))
	{
		sa(stack);
	}
	if (stack_sorted(stack) == 1)
	{
		if (stack->a[0] == max && stack->a[1] == min)
			ra(stack);
		else
			rra(stack);
	}
}

void	four_sorting(t_stack *stack)
{
	while (stack->a[3] != -1)
	{
		if (stack->a[0] != 0)
			ra(stack);
		else if (stack->a[0] == 0)
			pb(stack);
	}
	three_sorting(stack, 1, 3);
	pa(stack);
}

void	five_sorting(t_stack *stack)
{
	while (stack->a[3] != -1)
	{
		if (stack->a[0] != 0 && stack->a[0] != 1)
			ra(stack);
		else
			pb(stack);
	}
	three_sorting(stack, 2, 4);
	if (stack->b[0] < stack->b[1])
		sb(stack);
	pa(stack);
	pa(stack);
	return ;
}

void	radix_sorting(t_stack *stack)
{
	int	i;
	int	shift;
	int	bits;

	shift = 0;
	bits = 0;
	while ((stack->len - 1) >> bits != 0)
		bits++;
	while (shift < bits)
	{
		i = 0;
		while (i < stack->len)
		{
			if (((stack->a[0] >> shift) & 1) == 0)
				pb(stack);
			else
				ra(stack);
			i++;
		}
		while (stack->b[0] != -1)
			pa(stack);
		shift++;
	}
	return ;
}
