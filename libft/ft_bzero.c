/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:13:24 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/25 15:44:14 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*cs;
	size_t	i;

	cs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		cs[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	s1[] = "Hello World!";
	ft_bzero(s1, 4);
	printf("%s\n", s1);
}
*/
