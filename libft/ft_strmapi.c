/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 22:35:12 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/03 18:23:18 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	len = ft_strlen(s);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}

#include "testers.h"

char	to_upper_wrap(unsigned int i, char c)
{
	(void)i;
	return (toupper(c));
}

int	main(void)
{
	char	*tests[] = {"hello world", "", "H", "HELLO"};
	int		count = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < count; i++)
	{
		char	*result = ft_strmapi(tests[i], to_upper_wrap);
		char	*result_str;

		if (result)
			result_str = result;
		else
			result_str = "NULL";
		if (result)
			printf(GREEN);
		else
			printf(RED);
		printf("input: %s | result: %s\n\n", tests[i], result_str);
		printf(RESET);
		free(result);
	}
	return (0);
}
