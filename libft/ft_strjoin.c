/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 09:12:59 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:36:04 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

#include "testers.h"

int	main(void)
{
	t_strjoin_test	tests[] =
	{
		{"Hello ", "World!", "normal join, nothing weird"},
		{"", "World!", "s1 is empty"},
		{"Hello ", "", "s2 is empty"},
		{"", "", "both empty"}
	};
	int	count = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < count; i++)
	{
		char	*result = ft_strjoin(tests[i].s1, tests[i].s2);
		char	*label = tests[i].label;
		char	*result_str;

		if (result)
			result_str = result;
		else
			result_str = "NULL";
		if (result)
			printf(GREEN);
		else
			printf(RED);
		printf("desc: %s | s1: %s | s2: %s | result: %s\n\n",
			label, tests[i].s1, tests[i].s2, result_str);
		printf(RESET);
		free(result);
	}
	return (0);
}
