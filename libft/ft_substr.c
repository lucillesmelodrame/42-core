/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 16:14:34 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:36:26 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}

#include "testers.h"

int	main(void)
{
	t_substr	tests[] =
	{
		{"Hello World!", 0, 5, "normal, grab from the start"},
		{"Hello World!", 6, 5, "grab from somewhere in the middle"},
		{"Hello World!", 0, 0, "len 0, should just get empty"},
		{"Hello World!", 100, 5, "start way past the string"},
		{"Hello World!", 6, 100, "len way longer than whats left"},
		{"", 0, 5, "source is empty"},
		{"Hello", 5, 3, "start lands right on the null term"}
	};
	int	count = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < count; i++)
	{
		char	*result = ft_substr(tests[i].s, tests[i].start, tests[i].len);
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
		printf("desc: %s | result: %s\n\n", label, result_str);
		printf(RESET);
		free(result);
	}
	return (0);
}
