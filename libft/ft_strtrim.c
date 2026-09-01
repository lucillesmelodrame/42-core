/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 09:26:32 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:35:32 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	to_trim(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	while (to_trim(s1[i], set))
		i++;
	while (to_trim(s1[j], set) && j > 0)
		j--;
	if (j < i)
	{
		str = ft_strdup("");
		return (str);
	}
	str = malloc((j - i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] && i <= j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}

int	to_trim(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

#include "testers.h"

int	main(void)
{
	t_strtrim	tests[] =
	{
		{"  Hello World!  ", " ", "trim spaces off both ends"},
		{"xxHelloxx", "x", "trim a custom char off both ends"},
		{"Hello", "xyz", "nothing to trim, set isnt even in there"},
		{"xxxxx", "x", "the whole thing is trim chars"},
		{"", "x", "empty string to start with"},
		{"Hello", "", "empty set, nothing gets trimmed"}
	};
	int	count = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < count; i++)
	{
		char	*result = ft_strtrim(tests[i].s1, tests[i].set);
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
		printf("desc: %s | input: %s | result: %s\n\n", label, tests[i].s1, result_str);
		printf(RESET);
		free(result);
	}
	return (0);
}
