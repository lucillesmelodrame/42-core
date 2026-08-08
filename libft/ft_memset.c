/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:41:05 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/05 19:13:17 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t n)
{
	unsigned char	*csrc;
	unsigned char	cc;
	size_t	i;

	csrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		cc = (unsigned char )c;
		csrc[i] = cc;
		i++;
	}
	return (src);
}

/*
int	main(void)
{
	char	s1[20] = "Hello World!";
	memset(s1, 'a', 4);
	printf("%s\n", s1);
}
*/
