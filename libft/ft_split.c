/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 14:34:11 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:23:33 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	initialise_vars(int *start_index, size_t *i, size_t *j)
{
	*start_index = -1;
	*i = 0;
	*j = 0;
}

static size_t	count_words(const char *str, char delim)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '\0' && str[i] != delim
			&& (str[i + 1] == delim || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	*ft_free(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	*fill_word(const char *str, int start, size_t end)
{
	char	*word;
	size_t	len;

	len = end - start;
	word = ft_substr(str, start, len);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		start_index;
	size_t	i;
	size_t	j;

	initialise_vars(&start_index, &i, &j);
	result = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if ((s[i] != c && s[i] != '\0') && start_index < 0)
			start_index = i;
		else if ((s[i] == c || s[i] == '\0') && start_index >= 0)
		{
			result[j] = fill_word(s, start_index, i);
			if (!result[j])
				return (ft_free(result, j));
			start_index = -1;
			j++;
		}
		i++;
	}
	return (result);
}

#include "testers.h"

int	main(void)
{
	t_split	tests[] =
	{
		{"Hello World Foo", ' ', "normal split on spaces"},
		{"", ' ', "empty string"},
		{"     ", ' ', "its literally all delimiters"},
		{"Hello   World", ' ', "bunch of delimiters stacked together"},
		{" Hello World ", ' ', "delimiter right at the start and end"},
		{"HelloWorld", ' ', "no delimiter anywhere, should be one word"},
		{",Hello,,World,", ',', "different delimiter this time"}
	};
	int	count = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < count; i++)
	{
		char	**result = ft_split(tests[i].s, tests[i].c);

		printf("desc: %s\n", tests[i].label);
		if (!result)
			printf(RED "  got NULL back\n" RESET);
		else
		{
			for (int j = 0; result[j]; j++)
				printf("  [%d]: \"%s\"\n", j, result[j]);
			printf("\n");
		}
		if (result)
		{
			for (int j = 0; result[j]; j++)
				free(result[j]);
			free(result);
		}
	}
	return (0);
}
