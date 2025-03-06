
// --------------- test parsing avec printf----
// int main(int argc, char **argv)
// {
//     	int	i;
// 	int	j;
//     int minusc;

// 	if (argc <= 2)
// 		return (1);
// 	i = 0;
// 	while (++i < argc)
// 	{
//         j = 0;
//         minusc = 0;
// 		while (argv[i][j] != '\0' && argv[i][j])
//         {
//             if (argv[i][0] == '-' && argv[i][1] != '\0')
//             {
//                 if (minusc == 0)
//                 {
//                     //ft_printf("minusc : %d\n", minusc);
//                     ft_printf("%c", argv[i][j]);
//                     minusc++;
//                     j++;
//                 }
//             }
//             if (!ft_isdigit(argv[i][j]))
//             {
//                 ft_printf("caca en gros \n");
//                 return (1);
//             }
//             else
//             {
//                 ft_printf("%c", argv[i][j]);
//                 j++;
//             }
//         }
//         ft_printf(" ");
// 	}
//     return (0);
// }

//--------------------test sur sorting pour afficher valeurs
// ft_printf("\n");
// ft_printf("shift value : %d", shift);
// ft_printf("\n");
// ft_printf("\n\n--\nbitwise value : %d\n", ((stack->a[0] >> shift)
// 		&& 1));
// ft_printf("stack->a[0] value :%d\n", stack->a[0]);
// ft_printf("i value : %d\n--\n\n", i);

// j = 0;
// ft_printf("\n");
// ft_printf("----------------PB-------------\n");
// ft_printf("stack A\n");
// while (j < stack->len)
// {
// 	ft_printf("[%d] ", stack->a[j]);
// 	j++;
// }
// ft_printf("\n");
// ft_printf("stack B\n");
// j = 0;
// while (j < stack->len)
// {
// 	ft_printf("[%d] ", stack->b[j]);
// 	j++;
// }
// ft_printf("\n");
// ft_printf("----------------PB-------------\n");

// j = 0;
// ft_printf("\n");
// ft_printf("----------------RA-------------\n");
// ft_printf("stack A\n");
// while (j < stack->len)
// {
// 	ft_printf("[%d] ", stack->a[j]);
// 	j++;
// }
// ft_printf("\n");
// ft_printf("stack B\n");
// j = 0;
// while (j < stack->len)
// {
// 	ft_printf("[%d] ", stack->b[j]);
// 	j++;
// }
// ft_printf("\n");
// ft_printf("----------------RA-------------\n");

// j = 0;
// ft_printf("\n");
// ft_printf("----------------PA-------------\n");
// ft_printf("stack A\n");
// while (j < stack->len)
// {
// 	ft_printf("[%d] ", stack->a[j]);
// 	j++;
// }
// ft_printf("\n");
// ft_printf("stack B\n");
// j = 0;
// while (j < stack->len)
// {
// 	ft_printf("[%d] ", stack->b[j]);
// 	j++;
// }
// ft_printf("\n");
// ft_printf("----------------PA-------------\n");

// ft_printf("\n");
// ft_printf("shift value : %d", shift);
// ft_printf("\n");

//---------------------------------sorted display
// ft_printf("\n");
// ft_printf("stacka sorted\n");
// while (i < ps->stack->len)
// {
// 	ft_printf("{%d},", ps->stack->a[i]);
// 	i++;
// }
// ft_printf("\n");
// ft_printf("stackb sorted\n");
// i = 0;
// while (i < ps->stack->len)
// {
// 	ft_printf("/%d/,", ps->stack->b[i]);
// 	i++;
// }
// ft_printf("\n");
