#include "testers.h"
#include "libft.h"

int	main(void)
{
	printf("--- putchar_fd ---\n");
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);

	printf("--- putstr_fd ---\n");
	ft_putstr_fd("Hello World!", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("", 1);
	printf("(nothing above and no crash = good)\n");

	printf("--- putendl_fd ---\n");
	ft_putendl_fd("Hello World!", 1);
	ft_putendl_fd("", 1);

	printf("--- putnbr_fd ---\n");
	int	tests[] = {0, 123, -123, 2147483647, -2147483648};
	int	count = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < count; i++)
	{
		printf("input %d -> output: ", tests[i]);
		ft_putnbr_fd(tests[i], 1);
		printf("\n");
	}
	return (0);
}
