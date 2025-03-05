/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:50:49 by egache            #+#    #+#             */
/*   Updated: 2025/03/05 18:00:56 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	swap;
	int	i;

	swap = stack->a[0];
	i = 0;
	while (i < stack->len - 1 && stack->a[i] != -1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	if (stack->a[i] == -1)
		stack->a[i - 1] = swap;
	else
		stack->a[i] = swap;
}
void	rb(t_stack *stack)
{
	int	swap;
	int	i;

	swap = stack->b[0];
	i = 0;
	while (i < stack->len - 1 && stack->b[i] != -1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	if (stack->b[i] == -1)
		stack->b[i - 1] = swap;
	else
		stack->b[i] = swap;
}
void rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
