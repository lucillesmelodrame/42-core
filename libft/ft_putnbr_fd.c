/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 16:16:04 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/29 17:45:26 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	char			c;

	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		write(fd, "-", 1);
	}
	if (nbr != 0)
	{
		if (nbr > 9)
			ft_putnbr_fd(nbr / 10, fd);
		nbr %= 10;
	}
	c = nbr + '0';
	write(fd, &c, 1);
}
/*
void test(int n)
{
    printf("expected: %d | got: ", n);
    fflush(stdout);
    ft_putnbr_fd(n, 1);
    printf("\n");
}

int main(void)
{
    int tests[] = {0, 5, 9, 10, 124, 2147483647, -5, -124, -10, -2147483648};
    for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++)
        test(tests[i]);
}
*/
