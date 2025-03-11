/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:07:01 by egache            #+#    #+#             */
/*   Updated: 2025/03/11 13:51:18 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit(t_stack *stack, char *str, int ret)
{

	free_stack(stack);
	if (str != NULL)
		ft_putstr_fd(str, 2);
	exit(ret);
}
void	free_stack(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->a && stack)
		free(stack->a);
	if (stack->b && stack)
		free(stack->b);
	if (stack->presort && stack)
		free(stack->presort);
	if (stack->saved && stack)
		free(stack->saved);
	if (stack->args)
	{
		while (i < stack->len)
		{
			if (stack->args[i] != NULL)
				free(stack->args[i]);
			i++;
		}
		free(stack->args);
	}
	if (stack)
		free(stack);
}
