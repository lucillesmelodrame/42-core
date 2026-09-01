/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:02:36 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:37:30 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!find || !find[0])
		return ((char *)src);
	while (src[i] && i < n)
	{
		while (src[i + j] == find[j] && src[i + j] && i + j < n)
		{
			j++;
			if (find[j] == 0)
				return ((char *)src + i);
		}
		i++;
		j = 0;
	}
	return (0);
}

#include "testers.h"

int	main(void)
{
	char	*tests[] = {"Hello World!", "", "H", " "};
	int		count = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < count; i++)
	{
		char	*result = ft_strdup(tests[i]);
		char	*aresult = strdup(tests[i]);
		int		pass;
		char	*result_str;
		char	*aresult_str;

		if (result && aresult && ft_strncmp(result, aresult, ft_strlen(aresult) + 1) == 0)
			pass = 1;
		else
			pass = 0;
		if (result)
			result_str = result;
		else
			result_str = "NULL";
		if (aresult)
			aresult_str = aresult;
		else
			aresult_str = "NULL";
		if (pass)
			printf(GREEN);
		else
			printf(RED);
		printf("input: %s | result: %s | expected: %s\n\n", tests[i], result_str, aresult_str);
		printf(RESET);
		free(result);
		free(aresult);
	}
	return (0);
}
