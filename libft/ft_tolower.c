/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:52:04 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/01 15:29:46 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int	test[] = {'0', '9', 'A', 'Z', 'a', 'z', '/', ':', '@', '[', 0, -1, 127, 128, ' ', '\n'};
	for (size_t i = 0; i < 16; i++)
	{
		int result = ft_tolower(test[i]);
		int	aresult = tolower(test[i]);
		printf("input: %d | result: %d | expected: %d\n",test[i],  result, aresult);
	}
	return (0);
}

