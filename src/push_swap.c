/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:13:23 by teatime           #+#    #+#             */
/*   Updated: 2025/02/20 18:11:08 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_ps	*ps;

	ps = ft_calloc(1, sizeof(t_ps));
	ps->stack = ft_calloc(1, sizeof(t_stack));
	if (!ps)
		return (1);
	parsing(argc, argv, ps);
	// stack_initialisation(argc, argv, ps);
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
void	check_arguments(int argc, char **argv, t_ps *ps)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (empty_argument(argv[i]) == 1)
			free_exit(ps, "Error\nEmpty argument", EXIT_FAILURE);
		if (invalid_argument(argv[i]) == 1)
			free_exit(ps, "Error\nWrong arguments", EXIT_FAILURE);
		if (overflow_argument(argv[i]) == 1)
			free_exit(ps, "Error\nArgument above limit", EXIT_FAILURE);
		if (duplicate_argument(argc - 1, argv, i) == 1)
			free_exit(ps, "Error\nDuplicate number", EXIT_FAILURE);
		i++;
	}
	return ;
}
void	handle_multiple_argument(int argc, char **argv, t_ps *ps)
{
	check_arguments(argc, argv, ps);
	stack_initialisation(ps, argc, argv);
}

void	handle_single_argument(char *str, t_ps *ps)
{
	ps->strslen = 0;
	ps->strs = ft_split(str, ' ');
	if (ps->strs == NULL)
		free_exit(ps, "Error\nMalloc failed", EXIT_FAILURE);
	while (ps->strs[ps->strslen] != NULL)
		ps->strslen++;
	check_arguments(ps->strslen, ps->strs, ps);
	stack_initialisation(ps, ps->strslen, ps->strs);
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
