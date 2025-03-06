/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialisation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:08:41 by egache            #+#    #+#             */
/*   Updated: 2025/03/06 18:24:53 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_initialisation(t_stack *stack, char **args)
{
	if (stack_malloc(stack, stack->len) == 1)
		free_exit(stack, "Error\n", EXIT_FAILURE);
	if (stack_fill(stack, stack->len, args) == 1)
		free_exit(stack, "Error\n", EXIT_FAILURE);
	stack_indexing(stack);
}
int	stack_malloc(t_stack *stack, int len)
{
	stack->a = malloc((len) * sizeof(int));
	stack->b = malloc((len) * sizeof(int));
	stack->saved = malloc((len) * sizeof(int));
	stack->presort = malloc((len) * sizeof(int));
	if (!stack->a || !stack->b || !stack->saved || !stack->presort)
		return (1);
	return (0);
}
int	stack_fill(t_stack *stack, int len, char **tab)
{
	int	i;

	i = 0;
	while (i < len)
	{
		stack->saved[i] = (int)ft_atol_argument(tab[i]);
		stack->presort[i] = stack->saved[i];
		stack->b[i] = -1;
		i++;
	}
	ft_sort_int_tab(stack, len);
	return (0);
}

int	stack_indexing(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->len)
	{
		while (j < stack->len)
		{
			if (stack->saved[i] == stack->presort[j])
				stack->a[i] = j;
			j++;
		}
		i++;
		j = 0;
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
			if (stack->presort[j] < stack->presort[i])
			{
				swap = stack->presort[j];
				stack->presort[j] = stack->presort[i];
				stack->presort[i] = swap;
			}
			j++;
		}
		i++;
	}
}
