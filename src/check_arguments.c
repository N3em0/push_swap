/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:16:31 by egache            #+#    #+#             */
/*   Updated: 2025/03/13 20:46:06 by egache           ###   ########.fr       */
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

int	overflow_argument(char *arg)
{
	long	nb;

	nb = ft_atol_argument(arg);
	if (ft_strlen_digit(arg) > 11)
		return (1);
	if (nb > INT_MAX || nb < INT_MIN)
		return (1);
	else
		return (0);
}
size_t ft_strlen_digit(const char *str)
{
		size_t	i;
		size_t j;

	i = 0;
	j = 0;
	while (str[i] && (ft_isdigit(str[i]) == 0 || str[i] != '-'))
		i++;
	while (str[i + j] && (ft_isdigit(str[i]) == 1 || str[i] == '-'))
		j++;
	return (j);
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
