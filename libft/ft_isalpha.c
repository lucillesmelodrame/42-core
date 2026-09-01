/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 13:39:09 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/01 15:25:02 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
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
		int result = ft_isalpha(test[i]);
		int	aresult = isalpha(test[i]);
		printf("input: %d | result: %d | expected: %d\n",test[i],  result, aresult);
	}
	return (0);
}

