/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 14:44:02 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:37:52 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(int n);

char	*ft_itoa(int n)
{
	size_t			i;
	size_t			len;
	char			*res;
	unsigned int	nbr;

	len = count_len(n);
	nbr = n;
	if (n < 0)
		nbr *= -1;
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = len;
	while (i--)
	{
		res[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

static size_t	count_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

#include "testers.h"

int	main(void)
{
	int	tests[] = {0, 123, -123, 2147483647, -2147483648, 1, -1};
	int	count = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < count; i++)
	{
		char	*result = ft_itoa(tests[i]);
		char	expected[12];
		int		pass;
		char	*result_str;

		sprintf(expected, "%d", tests[i]);
		if (result && ft_strncmp(result, expected, ft_strlen(expected) + 1) == 0)
			pass = 1;
		else
			pass = 0;
		if (result)
			result_str = result;
		else
			result_str = "NULL";
		if (pass)
			printf(GREEN);
		else
			printf(RED);
		printf("input: %d | result: %s | expected: %s\n\n", tests[i], result_str, expected);
		printf(RESET);
		free(result);
	}
	return (0);
}
