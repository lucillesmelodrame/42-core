/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 21:44:39 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:38:45 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

#include "testers.h"

void	print_index(unsigned int i, char *c)
{
	printf("[%u]='%c' ", i, *c);
}

int	main(void)
{
	char	*tests[] = {"hello world", "", "H", "HELLO"};
	int		count = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < count; i++)
	{
		char	*buf = ft_strdup(tests[i]);

		printf("input: %s | output: ", tests[i]);
		ft_striteri(buf, print_index);
		printf("\n\n");
		free(buf);
	}
	return (0);
}
