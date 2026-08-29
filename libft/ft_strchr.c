/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 17:00:32 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/29 17:43:46 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (c == src[i])
			return ((char *)&src[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)src);
	return (0);
}
/*
int	main(void)
{
	char	s1[20] = "Hello World!";
	printf("%s\n", ft_strchr(s1, 'o'));
	// printf("%s\n", s1);
}
*/
