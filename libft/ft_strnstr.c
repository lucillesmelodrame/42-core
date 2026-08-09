/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:02:36 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/09 18:11:37 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>
/*
char	*ft_strnstr(const char *src, const char *find, size_t n)
{
	char	*csrc;
	char	*cfind;
	size_t	i;

	csrc = (char *)src;
	cfind = (char *)find;
	i = 0;
	if (cfind[i])
		return (csrc);
	while (csrc[i])
	{
		while (cfind[i] && i < n)
		{
			if (cfind[i] == csrc[i])
				return (cfind);
			i++;
		}
		i++;
	}
	return (0);
}
*/
int	main(void)
{
	char	s1[20] = "Hello World!";
	char	s2[4] = "el";
	char	*result = strnstr(s1, s2, 4);
	printf("%s\n", result);
}
