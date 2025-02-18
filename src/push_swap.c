/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:13:23 by teatime           #+#    #+#             */
/*   Updated: 2025/02/18 21:31:22 by egache           ###   ########.fr       */
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
	//printf("argv[1] : %s", argv[1]);
	// stack_initialisation(argc, argv, ps);
	free_exit(ps, "yessir", EXIT_SUCCESS);
	return (0);
}
void	valid_argument(int argc, char **argv, t_ps *ps)
{
	int	i;
	int	j;
	int	minusc;

	if (argc < 2)
		free_exit(ps, "Error\nWrong number of arguments", EXIT_FAILURE);
	i = 0;
	while (++i < argc)
	{
		j = 0;
		minusc = 0;
		if (argv[i][j] != '\0' && argv[i][j])
		{
            if (overflow_argument(argv[i]) == 1)
                free_exit(ps, "Error\nArgument above limit", EXIT_FAILURE);
            while (argv[i][j] != '\0' && argv[i][j])
            {
                //printf("len : %zu", ft_strlen(argv[i]));
                if (argv[i][0] == '-' && argv[i][1] != '\0')
                {
                    if (minusc++ == 0)
                        j++;
                }
                if (!ft_isdigit(argv[i][j]))
                    free_exit(ps, "Error\nWrong arguments", EXIT_FAILURE);
                else
                    j++;
            }
    }
		else
			free_exit(ps, "Error\nEmpty argument", EXIT_FAILURE);
	}
	return ;
}

int overflow_argument(char *arg)
{
    long nb;

    nb = ft_atoi(arg);
    printf("nb value : %ld\n", nb);
    if (nb > INT_MAX || nb <= INT_MIN)
        return (1);
    else
        return (0);
}
// argument vide SEEMS OK
// duplicata des nbr + overflow (avec una toi special)
