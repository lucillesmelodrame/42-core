/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 09:26:32 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/13 19:42:44 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	to_trim(char c, char const *set);

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
/*
int	main(void)
{
	char s1[20] = "";
	char *set = "hello";
	char *result = ft_strtrim(s1, set);
	printf("%sa\n", result);
}
*/
