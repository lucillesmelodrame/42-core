/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:31:30 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/01 15:26:58 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int	test[] = {'0', '9', 'A', 'Z', 'a', 'z', '/', ':', '@', '[', 0, -1, 127, 128, ' ', '\n'};
	for (size_t i = 0; i < 16; i++)
	{
		int result = ft_isprint(test[i]);
		int	aresult = isprint(test[i]);
		printf("input: %d | result: %d | expected: %d\n",test[i],  result, aresult);
	}
	return (0);
}

