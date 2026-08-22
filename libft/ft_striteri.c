/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 21:44:39 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/21 22:26:06 by melodrame        ###   ########.fr       */
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
/*
void	my_func(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c -= 32;
}

int	main(void)
{
	char	s[] =  "Hello World!";
	ft_striteri(s, my_func);
	printf("%s\n", s);
}
*/
