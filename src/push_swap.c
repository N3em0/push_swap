/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:13:23 by teatime           #+#    #+#             */
/*   Updated: 2025/03/05 19:24:48 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_ps	*ps;
	int i;

	i = 0;
	ps = ft_calloc(1, sizeof(t_ps));
	if (!ps)
		return (1);
	ps->stack = ft_calloc(1, sizeof(t_stack));
	if (!ps->stack)
		return (1);
	parsing(argc, argv, ps);
	radix_sorting(ps->stack);
	ft_printf("\n");
	ft_printf("stacka sorted\n");
	while (i < ps->stack->len)
	{
		ft_printf("{%d},", ps->stack->a[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("stackb sorted\n");
	i = 0;
	while (i < ps->stack->len)
	{
		ft_printf("/%d/,", ps->stack->b[i]);
		i++;
	}
	ft_printf("\n");
	free_exit(ps, "yessir\n", EXIT_SUCCESS);
	return (0);
}
void	parsing(int argc, char **argv, t_ps *ps)
{
	if (argc < 2)
		free_exit(ps, "Error\nWrong number of arguments", EXIT_FAILURE);
	else if (argc == 2)
		handle_single_argument(argv[1], ps);
	else
		handle_multiple_argument(argc - 1, argv + 1, ps);
}

long	ft_atol_argument(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
