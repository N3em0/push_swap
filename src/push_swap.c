/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:13:23 by teatime           #+#    #+#             */
/*   Updated: 2025/02/21 20:18:57 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_ps	*ps;
	int		i;

	ps = ft_calloc(1, sizeof(t_ps));
	if (!ps)
		return (1);
	ps->stack = ft_calloc(1, sizeof(t_stack));
	if (!ps->stack)
		return (1);
	parsing(argc, argv, ps);
	// ------------- test pb ------------
	ft_printf("\n\n");
	pb(ps->stack);
	ft_printf("pb\n");
	i = 0;
	while (i < ps->stack->len)
	{
		ft_printf("[%d],", ps->stack->a[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < ps->stack->len)
	{
		ft_printf("[%d],", ps->stack->b[i]);
		i++;
	}
	ft_printf("\n\n");
	pb(ps->stack);
	ft_printf("pb\n");
	i = 0;
	while (i < ps->stack->len)
	{
		ft_printf("[%d],", ps->stack->a[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < ps->stack->len)
	{
		ft_printf("[%d],", ps->stack->b[i]);
		i++;
	}
	ft_printf("\n\n");
	pb(ps->stack);
	pb(ps->stack);
	ft_printf("pb\n");
	i = 0;
	while (i < ps->stack->len)
	{
		ft_printf("[%d],", ps->stack->a[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < ps->stack->len)
	{
		ft_printf("[%d],", ps->stack->b[i]);
		i++;
	}
	ft_printf("\n\n");
	// ------------ test ra
	//pb(ps->stack);
	ra(ps->stack);
	ft_printf("ra\n");
	i = 0;
	while (i < ps->stack->len)
	{
		ft_printf("[%d],", ps->stack->a[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < ps->stack->len)
	{
		ft_printf("[%d],", ps->stack->b[i]);
		i++;
	}
	ft_printf("\n\n");
	ra(ps->stack);
	ft_printf("ra\n");
	i = 0;
	while (i < ps->stack->len)
	{
		ft_printf("[%d],", ps->stack->a[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < ps->stack->len)
	{
		ft_printf("[%d],", ps->stack->b[i]);
		i++;
	}
	ft_printf("\n\n");
	// pb(ps->stack);
	// ft_printf("pb\n");
	// i = 0;
	// while (i < ps->stack->len)
	// {
	// 	ft_printf("[%d],", ps->stack->a[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// i = 0;
	// while (i < ps->stack->len)
	// {
	// 	ft_printf("[%d],", ps->stack->b[i]);
	// 	i++;
	// }
	// ft_printf("\n\n");
	// pa(ps->stack);
	// ft_printf("pa\n");
	// i = 0;
	// while (i < ps->stack->len)
	// {
	// 	ft_printf("[%d],", ps->stack->a[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// i = 0;
	// while (i < ps->stack->len)
	// {
	// 	ft_printf("[%d],", ps->stack->b[i]);
	// 	i++;
	// }
	// ft_printf("\n\n");
	// pa(ps->stack);
	// ft_printf("pa\n");
	// i = 0;
	// while (i < ps->stack->len)
	// {
	// 	ft_printf("[%d],", ps->stack->a[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// i = 0;
	// while (i < ps->stack->len)
	// {
	// 	ft_printf("[%d],", ps->stack->b[i]);
	// 	i++;
	// }
	// ft_printf("\n\n");
	// pa(ps->stack);
	// ft_printf("pa\n");
	// i = 0;
	// while (i < ps->stack->len)
	// {
	// 	ft_printf("[%d],", ps->stack->a[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// i = 0;
	// while (i < ps->stack->len)
	// {
	// 	ft_printf("[%d],", ps->stack->b[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// sb(ps->stack);
	// ft_printf("sb\n");
	// i = 0;
	// while (i < ps->stack->len)
	// {
	// 	ft_printf("[%d],", ps->stack->a[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// i = 0;
	// while (i < ps->stack->len)
	// {
	// 	ft_printf("[%d],", ps->stack->b[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// ss(ps->stack);
	// ft_printf("ss\n");
	// i = 0;
	// while (i < ps->stack->len)
	// {
	// 	ft_printf("[%d],", ps->stack->a[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// i = 0;
	// while (i < ps->stack->len)
	// {
	// 	ft_printf("[%d],", ps->stack->b[i]);
	// 	i++;
	// }
	ft_printf("\n");
	// i = 0;
	// while (i < ps->stack->len)
	// {
	// 	ft_printf("(%d),", ps->stack->b[i]);
	// 	i++;
	// }
	// ft_printf("\n\n");
	// pa(ps->stack);
	// i = 0;
	// while (i < ps->stack->len)
	// {
	// 	ft_printf("[%d],", ps->stack->a[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// i = 0;
	// while (i < ps->stack->len)
	// {
	// 	ft_printf("(%d),", ps->stack->b[i]);
	// 	i++;
	// }
	// ft_printf("\n\n");
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
void	check_arguments(t_ps *ps, char **args)
{
	int	i;

	i = 0;
	while (i < ps->stack->len)
	{
		if (empty_argument(args[i]) == 1)
			free_exit(ps, "Error\nEmpty argument", EXIT_FAILURE);
		if (invalid_argument(args[i]) == 1)
			free_exit(ps, "Error\nWrong arguments", EXIT_FAILURE);
		if (overflow_argument(args[i]) == 1)
			free_exit(ps, "Error\nArgument above limit", EXIT_FAILURE);
		if (duplicate_argument(ps->stack->len - 1, args, i) == 1)
			free_exit(ps, "Error\nDuplicate number", EXIT_FAILURE);
		i++;
	}
	return ;
}
void	handle_multiple_argument(int len, char **args, t_ps *ps)
{
	ps->stack->len = len;
	check_arguments(ps, args);
	stack_initialisation(ps, args);
}

void	handle_single_argument(char *arg, t_ps *ps)
{
	t_stack	*stack;

	stack = ps->stack;
	stack->len = 0;
	stack->args = ft_split(arg, ' ');
	if (stack->args == NULL)
		free_exit(ps, "Error\nMalloc failed", EXIT_FAILURE);
	while (stack->args[stack->len] != NULL)
		stack->len++;
	check_arguments(ps, stack->args);
	stack_initialisation(ps, stack->args);
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
