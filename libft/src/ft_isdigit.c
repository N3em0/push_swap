/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:38:17 by egache            #+#    #+#             */
/*   Updated: 2025/02/19 18:13:35 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}
/*
#include <stdio.h>

int	main(void)
{
		char str[7] = "";
		printf("%d", ft_str_is_numeric(str));

}*/

// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	(void)argc;

// 	printf("isdigit value : %d", ft_isdigit(argv[1][0]));
// }
