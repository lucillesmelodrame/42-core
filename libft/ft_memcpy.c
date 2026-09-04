/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:17:42 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/04 02:57:01 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;

	cdest = (char *)dest;
	csrc = (char *)src;
	if (n == 0 || (!src && !dest))
		return (dest);
	while (n--)
		cdest[n] = csrc[n];
	return (dest);
}

#include "testers.h"
int	main(void)
{
	char	dest[] = "uhhhhhhhhh";
	char	src[] = "KillerBunnt";
//	ft_memcpy(dest, src, 10);
	memcpy(dest, src, 10);
	printf("%s\n", dest);
}
