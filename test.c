#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// void	ft_putnbr_bin(int n)

// {
// 	char *base = "01";

// 	if (n >= 2)
// 		ft_putnbr_bin(n / 2);
// 	write(1, &base[n % 2], 1);
// }

int	main(int argc, char **argv)

{
	// int x = atoi(argv[1]);
	// int b = atoi(argv[2]);
	// int shift = atoi(argv[3]);
	// int y = x;

	// x = x >> shift;
	// int c = x & b;
	// printf(" <- valeur 1 base binaire / valeur 1 base 10 -> %d", y);
	// ft_putnbr_bin(y);
	// printf("\n");
	// printf(" <- valeur 2 base binaire / valeur 2 base 10 -> %d", b);
	// ft_putnbr_bin(b);
	// printf("\n");
	// printf(" <- valeur base binaire shift / valeur base 10 shift -> %d", x);
	// ft_putnbr_bin(x);
	// printf("\n");
	// printf(" <- valeur bitwise base binaire / valeur bitwise -> %d", c);
	// ft_putnbr_bin(c);
	// printf("\n");
	// printf("\n");
	// printf("\n");
	printf("%d", atoi(argv[1]) >> atoi(argv[2]));
	return (0);
}
