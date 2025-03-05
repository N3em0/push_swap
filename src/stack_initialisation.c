/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialisation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:08:41 by egache            #+#    #+#             */
/*   Updated: 2025/03/05 19:14:06 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stack_initialisation(t_ps *ps, char **args)
{
	if (stack_malloc(ps->stack, ps->stack->len) == 1)
		free_exit(ps, "Error\nMalloc failed", EXIT_FAILURE);
	if (stack_fill(ps->stack, ps->stack->len, args) == 1)
		free_exit(ps, "Error\nMalloc failed", EXIT_FAILURE);
	stack_indexing(ps->stack);
}
int stack_malloc(t_stack *stack, int len)
{
	stack->a = malloc((len) * sizeof(int));
	stack->b = malloc((len) * sizeof(int));
	stack->saved = malloc((len) * sizeof(int));
	stack->presort = malloc((len) * sizeof(int));
	if (!stack->a || !stack->b || !stack->saved || !stack->presort)
		return (1);
	return (0);
}
int stack_fill(t_stack *stack, int len, char **tab)
{
	int i;

	i = 0;
	ft_printf("stacksaved\n");
	while (i < len)
	{
		stack->saved[i] = (int)ft_atol_argument(tab[i]);
		stack->presort[i] = stack->saved[i];
		stack->b[i] = -1;
		ft_printf("[%d],", stack->saved[i]);
		i++;
	}
	// ft_printf("\n");
	ft_sort_int_tab(stack, len);
	// i = 0;
	// while (i < len)
	// {
	// 	ft_printf("(%d),", stack->presort[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	return (0);
}

int stack_indexing(t_stack *stack)
{
	int i;
	int j;

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
	i = 0;
	ft_printf("\n");
	ft_printf("stacka\n");
	while (i < stack->len)
	{
		ft_printf("{%d},", stack->a[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("stackb\n");
	i = 0;
	while (i < stack->len)
	{
		ft_printf("/%d/,", stack->b[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("max : %d", ft_strlen(ft_itoa(stack->presort[stack->len - 1])));
	ft_printf("\n");
	return (0);
}

void ft_sort_int_tab(t_stack *stack, int len)
{
	int i;
	int j;
	int swap;

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
