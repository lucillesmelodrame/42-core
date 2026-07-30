/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:17:42 by sonfong           #+#    #+#             */
/*   Updated: 2026/07/30 16:38:05 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;

	cdest = (char *)dest;
	csrc = (char *)src;
	if (n == 0)
		return (0);
	while (n--)
		*cdest++ = *csrc++;
	return (dest);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[10] = "Hello";
	char	*s2 = "Hi!";
	ft_memcpy(s1, s2, 2);
	printf("%s\n", s1);
}
