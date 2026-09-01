/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:21:42 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:19:02 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				sign;
	unsigned int	res;
	int				i;

	sign = 1;
	res = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = 10 * res + (nptr[i++] - '0');
	res *= sign;
	return ((int)res);
}

#include "testers.h"

int	main(void)
{
	char	*tests[] =
	{
		"123", "-123", "  456", "+789", "0", "-0",
		"2147483647", "-2147483648", "abc123", "123abc",
		"   -42", "++123", "--123", ""
	};
	int	count = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < count; i++)
	{
		int	result = ft_atoi(tests[i]);
		int	aresult = atoi(tests[i]);

		if (result == aresult)
			printf(GREEN);
		else
			printf(RED);
		printf("input: \"%s\" | result: %d | expected: %d\n\n", tests[i], result, aresult);
		printf(RESET);
	}
	return (0);
}
