/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 17:00:32 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:28:30 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if ((unsigned char)c == (unsigned char)src[i])
			return ((char *)&src[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&src[i]);
	return (NULL);
}

#include "testers.h"

int	main(void)
{
	t_strchr	tests[] =
	{
		{"Hello World!", 'o', "o shows up twice, should get 1st one"},
		{"Hello World!", 'z', "z isnt in here at all"},
		{"Hello World!", '\0', "looking for the null term itself"},
		{"", 'a', "empty string, obviously not found"},
		{"", '\0', "empty string but find the term"},
		{"aaa", 'a', "all the same char, first vs last matters here"}
	};
	int	count = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < count; i++)
	{
		char	*result = ft_strchr(tests[i].s, tests[i].c);
		char	*aresult = strchr(tests[i].s, tests[i].c);
		char	*label = tests[i].label;

		if (result == aresult)
			printf(GREEN);
		else
			printf(RED);
		printf("input: %s | c: %d | desc: %s | result: %s | expected: %s\n\n",
			tests[i].s, tests[i].c, label,
			result ? result : "NULL", aresult ? aresult : "NULL");
		printf(RESET);
	}
	return (0);
}
