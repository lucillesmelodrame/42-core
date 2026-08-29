/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 17:00:32 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/29 17:44:06 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	i;

	i = ft_strlen(src);
	while (i--)
	{
		if (c == src[i])
			return ((char *)&src[i]);
		i--;
	}
	if (c == '\0')
		return ((char *)src);
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "Hello World!";
	printf("%s\n", ft_strrchr(s1, 'o'));
}
*/
