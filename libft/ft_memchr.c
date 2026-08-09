/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:59:33 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/09 17:51:31 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	char	*csrc;
	size_t	i;

	csrc = (char *)src;
	i = 0;
	while (n--)
	{
		if (c == csrc[i])
			return (&csrc[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "Hello World!";
	void	*result = ft_memchr(s1, 'o', 6);
	char	*cresult = (char *)result; 
	printf("%s\n", cresult);
}
*/
