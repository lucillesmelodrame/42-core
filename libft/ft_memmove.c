/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:11:02 by sonfong           #+#    #+#             */
/*   Updated: 2026/07/29 18:16:45 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_memmove(const void *dest, const void *src, int n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	const unsigned char	*temp;

	p1 = (const unsigned char *)dest;
	p2 = (const unsigned char *)src;
	if (n == 0)
		return (0);
	while (*p1 && *p1 < n)
	{
		temp = p1;
		p1++;
		
	}
	p2 = temp;
	return (p2);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[10] = "Hello";
	char	s2[] = "World!";

	ft_memmove(s1, s2, 3);
	printf("%s\n", s2);
}
