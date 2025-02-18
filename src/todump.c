
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
