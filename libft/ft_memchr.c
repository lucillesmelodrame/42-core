/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:59:33 by sonfong           #+#    #+#             */
/*   Updated: 2026/07/30 17:19:43 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	char	*csrc;

	csrc = (char *)src;
	while (n-- && *csrc)
	{
		if (c == *csrc)
			return (csrc);
		csrc++;
	}
	return (0);
}
