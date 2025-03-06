/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:13:23 by teatime           #+#    #+#             */
/*   Updated: 2025/03/06 18:34:42 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		free_exit(stack, "Error\n", EXIT_FAILURE);
	parsing(argc, argv, stack);
	radix_sorting(stack);
	free_exit(stack, NULL, EXIT_SUCCESS);
	return (0);
}
void	parsing(int argc, char **argv, t_stack *stack)
{
	if (argc < 2)
		free_exit(stack, NULL, EXIT_FAILURE);
	else if (argc == 2)
		handle_single_argument(argv[1], stack);
	else
		handle_multiple_argument(argc - 1, argv + 1, stack);
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
