/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teatime <teatime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 00:21:18 by teatime           #+#    #+#             */
/*   Updated: 2025/02/22 00:39:30 by teatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack *stack)
{
    int swap;
    int i;

    i = stack->len - 1;
    swap = 0;
    while (i > 0)
    {
        if (stack->a[i] != 0 && swap == 0)
            swap = stack->a[i];
        if (stack->a[i] != 0)
            stack->a[i] = stack->a[i - 1];
        i--;
    }
    stack->a[0] = swap;
}

void rrb(t_stack *stack)
{
    int swap;
    int i;

    i = stack->len - 1;
    swap = 0;
    while (i > 0)
    {
        if (stack->b[i] != 0 && swap == 0)
            swap = stack->b[i];
        if (stack->b[i] != 0)
            stack->b[i] = stack->b[i - 1];
        i--;
    }
    stack->b[0] = swap;
}

void rrr(t_stack *stack)
{
    rra(stack);
    rrb(stack);
}