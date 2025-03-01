/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:13:23 by teatime           #+#    #+#             */
/*   Updated: 2025/02/22 12:43:31 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_ps	*ps;

	ps = ft_calloc(1, sizeof(t_ps));
	if (!ps)
		return (1);
	ps->stack = ft_calloc(1, sizeof(t_stack));
	if (!ps->stack)
		return (1);
	parsing(argc, argv, ps);
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
	if (str[i] == '-')
	{
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
