/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 19:58:29 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:36:59 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1) + 1;
	tmp = malloc(j * sizeof(char));
	if (!tmp)
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
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
