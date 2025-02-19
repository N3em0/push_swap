/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:13:23 by teatime           #+#    #+#             */
/*   Updated: 2025/02/19 20:12:13 by egache           ###   ########.fr       */
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
	valid_argument(argc, argv, ps);
	// printf("argv[1] : %s", argv[1]);
	// stack_initialisation(argc, argv, ps);
	free_exit(ps, "yessir", EXIT_SUCCESS);
	return (0);
}
void	valid_argument(int argc, char **argv, t_ps *ps)
{
	int	i;

	if (argc < 2)
		free_exit(ps, "Error\nWrong number of arguments", EXIT_FAILURE);
	i = 0;
	while (++i < argc)
	{
		if (empty_argument(argv[i]) == 1)
			free_exit(ps, "Error\nEmpty argument", EXIT_FAILURE);
		if (invalid_argument(argv[i]) == 1)
			free_exit(ps, "Error\nWrong arguments", EXIT_FAILURE);
		if (overflow_argument(argv[i]) == 1)
			free_exit(ps, "Error\nArgument above limit", EXIT_FAILURE);
		if (i > 1 && duplicate_argument(argv[i], argv[i - 1]) == 1)
			free_exit(ps, "Error\nDuplicate number", EXIT_FAILURE);
	}
	return ;
}

int	overflow_argument(char *str)
{
	long	nb;

	nb = ft_atoi_argument(str);
	printf("nb value : %ld\n\n", nb);
	if (nb > INT_MAX || nb <= INT_MIN)
		return (1);
	else
		return (0);
}

long	ft_atoi_argument(char *str)
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

int	duplicate_argument(char *str1, char *str2)
{
	printf("allo ?\n");
	if (ft_atoi_argument(str1) == ft_atoi_argument(str2))
		return (1);
	else
		return (0);
}

int	invalid_argument(char *str)
{
	int	i;
	int	minusc;
	int	nbc;

	i = 0;
	minusc = 0;
	nbc = 0;
	while (str[i] != '\0' && str[i])
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]) == 1)
		{
			if (minusc++ == 0)
				i++;
		}
		else if (ft_isdigit(str[i]) == 1 && nbc < 1)
		{
			while (ft_isdigit(str[i]) == 1)
				i++;
			nbc++;
		}
		else if (str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

int	empty_argument(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\0' && str[i])
		return (0);
	else
		return (1);
}
//
