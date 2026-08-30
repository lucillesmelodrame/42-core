/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:42:59 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/30 18:59:56 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = ft_strlen(src);
	if (n >= len + 1)
		ft_memcpy(dest, src, len + 1);
	else if (n != 0)
	{
		ft_memcpy(dest, src, n - 1);
		dest[n - 1] = '\0';
	}
	return (len);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char 	dest[] = "Hello";
	char	src[] = "World!";
	size_t	n = strlcpy(dest, src, 6);
	printf("%ld\n", n);
	printf("%s\n", dest);
}
*/
