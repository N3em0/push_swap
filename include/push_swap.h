/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:04:28 by teatime           #+#    #+#             */
/*   Updated: 2025/02/19 18:33:35 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_ps
{
	char	*stacka;
	char	*stackb;
}			t_ps;

int			main(int argc, char **argv);

void		valid_argument(int argc, char **argv, t_ps *ps);
int			invalid_argument(char *str);
int			empty_argument(char *str);
int			overflow_argument(char *str);
int			duplicate_argument(char *str1, char *str2);
long		ft_atoi_argument(char *str);

void		free_exit(t_ps *ps, char *str, int ret);
// void	struct_initialisation(t_ps *ps);

// void		stack_initialisation(int argc, char **argv, t_ps *ps);
// int			stack_malloc(int argc, char **argv, t_ps *ps);
// int			stack_copy(t_ps *ps);
#endif
