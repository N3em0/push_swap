/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialisation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:08:41 by egache            #+#    #+#             */
/*   Updated: 2025/02/20 20:23:08 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_initialisation(t_ps *ps, int len, char **tab)
{
	if (stack_malloc(ps->stack, len) == 1)
		free_exit(ps, "Error\nMalloc failed", EXIT_FAILURE);
	if (stack_fill(ps->stack, len, tab) == 1)
		free_exit(ps, "Error\nMalloc failed", EXIT_FAILURE);
}
int	stack_malloc(t_stack *stack, int len)
{
	stack->a = malloc((len) * sizeof(int));
	stack->b = malloc((len) * sizeof(int));
	if (!stack->a || !stack->a)
		return (1);
	return (0);
}
int	stack_fill(t_stack *stack, int len, char **tab)
{
	int	i;

	i = 0;
	while (i < len)
	{
		stack->a[i] = (int)ft_atol_argument(tab[i]);
		ft_printf("[%d],", stack->a[i]);
		i++;
	}
	ft_printf("\n");
	ft_sort_int_tab(stack, len);
	i = 0;
	while (i < len)
	{
		ft_printf("(%d),", stack->a[i]);
		i++;
	}
	return (0);
}

void	ft_sort_int_tab(t_stack *stack, int len)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (stack->a[j] < stack->a[i])
			{
				swap = stack->a[j];
				stack->a[j] = stack->a[i];
				stack->a[i] = swap;
			}
			j++;
		}
		i++;
	}
}
