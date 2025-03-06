/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:57:46 by egache            #+#    #+#             */
/*   Updated: 2025/03/06 19:49:50 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sorting(t_stack *stack)
{
	int	i;
	int	shift;
	int	bits;
	int	max;

	shift = 0;
	bits = 0;
	max = stack->len - 1;
	while (max >> bits != 0)
		bits++;
	while (shift < bits)
	{
		i = 0;
		while (i < stack->len)
		{
			if (((stack->a[0] >> shift) & 1) == 0)
			{
				pb(stack);
				write(1, "pb", 2);
				write(1, "\n", 1);

			}
			else
			{
				ra(stack);
				write(1, "ra", 2);
				write(1, "\n", 1);
			}
			i++;
		}
		while (stack->b[0] != -1)
		{
			pa(stack);
				write(1, "pa", 2);
				write(1, "\n", 1);
		}
		shift++;
	}
	return ;
}
