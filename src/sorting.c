/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:57:46 by egache            #+#    #+#             */
/*   Updated: 2025/03/05 20:30:04 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sorting(t_stack *stack)
{
	int	i;
	int	j;
	int	shift;
	int	max;

	shift = 0;
	max = ft_strlen(ft_itoa(stack->presort[stack->len - 1]));
	while (shift < max)
	{
		i = 0;
		while (i < stack->len)
		{
			ft_printf("\n");
			ft_printf("shift value : %d", shift);
			ft_printf("\n");
			ft_printf("\n\n--\nbitwise value : %d\n", ((stack->a[0] >> shift)
					&& 1));
			ft_printf("stack->a[0] value :%d\n", stack->a[0]);
			ft_printf("i value : %d\n--\n\n", i);
			if (((stack->a[0] >> shift) && 1) == 0)
			{
				pb(stack);
				j = 0;
				ft_printf("\n");
				ft_printf("----------------PB-------------\n");
				ft_printf("stack A\n");
				while (j < stack->len)
				{
					ft_printf("[%d] ", stack->a[j]);
					j++;
				}
				ft_printf("\n");
				ft_printf("stack B\n");
				j = 0;
				while (j < stack->len)
				{
					ft_printf("[%d] ", stack->b[j]);
					j++;
				}
				ft_printf("\n");
				ft_printf("----------------PB-------------\n");
			}
			else if (((stack->a[0] >> shift) && 1) == 1)
			{
				ra(stack);
				j = 0;
				ft_printf("\n");
				ft_printf("----------------RA-------------\n");
				ft_printf("stack A\n");
				while (j < stack->len)
				{
					ft_printf("[%d] ", stack->a[j]);
					j++;
				}
				ft_printf("\n");
				ft_printf("stack B\n");
				j = 0;
				while (j < stack->len)
				{
					ft_printf("[%d] ", stack->b[j]);
					j++;
				}
				ft_printf("\n");
				ft_printf("----------------RA-------------\n");
			}
			i++;
		}
		while (stack->b[0] != -1)
		{
			pa(stack);
			j = 0;
			ft_printf("\n");
			ft_printf("----------------PA-------------\n");
			ft_printf("stack A\n");
			while (j < stack->len)
			{
				ft_printf("[%d] ", stack->a[j]);
				j++;
			}
			ft_printf("\n");
			ft_printf("stack B\n");
			j = 0;
			while (j < stack->len)
			{
				ft_printf("[%d] ", stack->b[j]);
				j++;
			}
			ft_printf("\n");
			ft_printf("----------------PA-------------\n");
		}
		shift++;
		ft_printf("\n");
		ft_printf("shift value : %d", shift);
		ft_printf("\n");
	}
	return ;
}
