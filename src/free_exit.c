/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:07:01 by egache            #+#    #+#             */
/*   Updated: 2025/03/04 17:56:00 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit(t_ps *ps, char *str, int ret)
{
	int	i;

	i = 0;
	if (ps->stack->a && ps->stack)
		free(ps->stack->a);
	if (ps->stack->b && ps->stack)
		free(ps->stack->b);
	if (ps->stack->presort && ps->stack)
		free(ps->stack->presort);
	if (ps->stack->saved && ps->stack)
		free(ps->stack->saved);
	if (ps->stack->args)
	{
		while (i < ps->stack->len)
		{
			if (ps->stack->args[i] != NULL)
				free(ps->stack->args[i]);
			i++;
		}
		free(ps->stack->args);
	}
	if (ps->stack)
		free(ps->stack);
	if (ps)
		free(ps);
	if (str != NULL)
		ft_putstr_fd(str, 2);
	exit(ret);
}
// void	free_stack(t_stack *stack)
// {

// }
