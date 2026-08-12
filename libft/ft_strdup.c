/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 19:58:29 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/12 16:52:05 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1) + 1;
	tmp = malloc(j * sizeof(char));
	if (!tmp)
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

/* int	main(void)
{
	char	s1[] = "Hello World!";
	char	*result = ft_strdup(s1);
	printf("%s\n", result);
} */
