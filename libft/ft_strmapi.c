/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 22:35:12 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/22 01:29:29 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	len = ft_strlen(s);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
/*
char	my_map(unsigned int n, char c)
{
	if (n % 2 == 0)
		c -= 32;
	return (c);
}

int	main(void)
{
	char	s[] = "hello world";
	char	*res = ft_strmapi(s, my_map);
	printf("%s\n", res);
}
*/
