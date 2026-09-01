/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:32:50 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 04:37:18 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

#include "testers.h"

int	main(void)
{
	char	*tests[] = {"Hello World!", "", "H", "Hello\0World", " "};
	int		count = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < count; i++)
	{
		size_t	result = ft_strlen(tests[i]);
		size_t	aresult = strlen(tests[i]);

		if (result == aresult)
			printf(GREEN);
		else
			printf(RED);
		printf("input: %s | result: %zu | expected: %zu\n\n", tests[i], result, aresult);
		printf(RESET);
	}
	return (0);
}
