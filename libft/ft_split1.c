/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 01:02:49 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/26 17:34:30 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_word(char const c, char delim);

static int	count_words(char const *str, char delim);

static void	free_split(char **result, int box_index);

char	**ft_split(char const *s, char delim)
{
	size_t	word_start_index;
	size_t	in_word_state;
	size_t	box_index;
	size_t	i;
	size_t	j;
	size_t	len;
	char	**result;

	word_start_index = 0;
	in_word_state = 0;
	box_index = 0;
	i = 0;
	result = ft_calloc(count_words(s, delim) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	while (s[i])
	{
		if (in_word(s[i], delim) && in_word_state == 0)
		{
			word_start_index = i;
			in_word_state = 1;
		}
		if (!in_word(s[i], delim) && in_word_state == 1)
		{
			in_word_state = 0;
			len = i - word_start_index;
			result[box_index] = ft_calloc(len + 1, sizeof(char));
			if (!result[box_index])
			{
				free_split(result, 0);
				return (NULL);
			}
			j = 0;
			while (j < len)
			{
				result[box_index][j] = s[j + word_start_index];
				j++;
			}
			box_index++;
		}
		i++;
	}
	if (in_word_state == 1)
	{
		len = i - word_start_index;
		result[box_index] = ft_calloc(len + 1, sizeof(char));
		if (!result[box_index])
		{
			free_split(result, 0);
			return (NULL);
		}
		j = 0;
		while (j < len)
		{
			result[box_index][j] = s[j + word_start_index];
			j++;
		}
		box_index++;
	}
	result[box_index] = NULL;
	return (result);
}

static int	in_word(char const c, char delim)
{
	if (c != delim && c != '\0')
		return (1);
	else
		return (0);


static int	count_words(char const *str, char delim)
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

static void	free_split(char **result, int box_index)
{
	while (result[box_index])
	{
		free(result[box_index]);
		box_index++;
	}
	free(result);
}
/*
int	main(void)
{
	char	s1[20] = ",hello,,world,";
	char	delim = ',';
	char	**result = ft_split(s1, delim);
	int	i = 0;
	while (result[i])
	{
		printf("[%s]\n", result[i]);
		i++;
	}
	free_split(result, 0);
	return (0);
}
*/
