/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:41:02 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/09 04:46:37 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (i < n && s1[i] && s1[i] == s2[i])
	{
		while (s1[i] == s2[i])
			i++;
	}
	return (s1[i] - s2[i]);
}

/*
int	main(void)
{
	char	s1[] = "Hello";
	char	s2[] = "World!";
	printf("%d\n", ft_strncmp(s1, s2, 3));
} */
