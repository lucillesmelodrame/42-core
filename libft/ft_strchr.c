/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 17:00:32 by sonfong           #+#    #+#             */
/*   Updated: 2026/07/30 18:07:46 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char *src, int c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (c == src[i])
			return(&src[i]);
		i++;
	}
	if (c == '\0')
		return (src);
	return (0);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "Hello World!";
	printf("%s\n", ft_strchr(s1, 'o'));
}
