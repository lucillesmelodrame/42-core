/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:32:50 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/04 02:42:27 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

#include "testers.h"

int	main(void)
{
	char	str[] = "Heather, Heather and Heather";
	size_t	res = ft_strlen(str);
	size_t	ares = strlen(str);
	printf("result: %ld | expected: %ld\n", res, ares);
}
