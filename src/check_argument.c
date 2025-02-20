/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:16:31 by egache            #+#    #+#             */
/*   Updated: 2025/02/20 18:23:19 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate_argument(int argc, char **argv, int pos)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_atol_argument(argv[pos]) == ft_atol_argument(argv[i])
			&& pos != i)
			return (1);
		else
			i++;
	}
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
		if (str[i] == '-' && ft_isdigit(str[i + 1]) == 1 && minusc++ == 0)
			i++;
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
int	overflow_argument(char *str)
{
	long	nb;

	nb = ft_atol_argument(str);
	if (nb > INT_MAX || nb <= INT_MIN)
		return (1);
	else
		return (0);
}
//check argument size
