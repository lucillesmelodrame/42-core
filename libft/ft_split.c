/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 14:34:11 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/28 02:12:21 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static int	in_word(char s, char delim);

static size_t	count_words(const char *str, char delim);

static void	*ft_free(char **str, int count);

static char	*fill_word(const char *str, int start, size_t end);

char	**ft_split(char const *s, char c)
{
	char	**result;
	int	start_index;
	size_t	i;
	size_t	j;

	start_index = -1;
	i = 0;
	j = 0;
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (in_word(s[i], c) && start_index < 0)
			start_index = i;
		else if (!in_word(s[i], c) && start_index >= 0)
		{
			if (!(result[j] = fill_word(s, start_index, i)))
				return (ft_free(result, j));
			start_index = -1;
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}

static int	in_word(char c, char delim)
{
	if (c != delim && c != '\0')
		return (1);
	else
		return (0);
}

static size_t	count_words(const char *str, char delim)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (in_word(str[i], delim) &&
			(str[i + 1] == delim || str[i + 1] == '\0'))
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

#include <stdio.h>
int	main(void)
{
	char	s1[] = "       hello      world         ";
	char	delim = ' ';
	char	**result = ft_split(s1, delim);
	int	i = 0;
	while (result[i])
	{
		printf("[%s]\n", result[i]);
		i++;
	}
	return (0);
}
