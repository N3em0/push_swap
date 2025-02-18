/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:07:01 by egache            #+#    #+#             */
/*   Updated: 2025/02/18 19:17:09 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit(t_ps *ps, char *str, int ret)
{
	if (ps->stacka)
		free(ps->stacka);
	if (ps->stackb)
		free(ps->stackb);
	if (ps)
		free(ps);
	if (str != NULL)
		ft_putstr_fd(str, 2);
	exit(ret);

}
