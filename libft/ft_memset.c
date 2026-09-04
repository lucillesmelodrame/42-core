/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:41:05 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/04 03:02:13 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t n)
{
	unsigned char	*csrc;
	unsigned char	cc;
	size_t			i;

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

#include "testers.h"

int	main()
{
	char	src[] = "Summer and Ivan";
	int	c = 'a';
	ft_memset(src, c, 5);
	memset(src, c, 5);
	printf("%s\n", src);
}
