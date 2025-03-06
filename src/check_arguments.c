/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:16:31 by egache            #+#    #+#             */
/*   Updated: 2025/03/06 18:40:08 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	empty_argument(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] != '\0' && arg[i])
		return (0);
	else
		return (1);
}

int	invalid_argument(char *arg)
{
	int	i;
	int	signc;
	int	nbc;

	i = 0;
	signc = 0;
	nbc = 0;
	while (arg[i] != '\0' && arg[i])
	{
		if (arg[i] == '-' && ft_isdigit(arg[i + 1]) == 1 && signc++ == 0)
			i++;
		else if (arg[i] == '+' && ft_isdigit(arg[i + 1]) == 1 && signc++ == 0)
			i++;
		else if (ft_isdigit(arg[i]) == 1 && nbc < 1)
		{
			while (ft_isdigit(arg[i]) == 1)
				i++;
			nbc++;
		}
		else if (arg[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

int	duplicate_argument(int len, char **args, int pos)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (ft_atol_argument(args[pos]) == ft_atol_argument(args[i])
			&& pos != i)
			return (1);
		else
			i++;
	}
	return (0);
}

int	overflow_argument(char *arg)
{
	long	nb;

	// if (ft_strlen(arg) > 11)
	// 	return (1);
	nb = ft_atol_argument(arg);
	if (nb > INT_MAX || nb < INT_MIN)
		return (1);
	else
		return (0);
}
