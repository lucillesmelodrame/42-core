/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 14:44:02 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/21 16:05:53 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(int n);

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	len;
	char	*res;
	unsigned int	nbr;

	len = count_len(n);
	nbr = n;
	if (n < 0)
		nbr *= -1;
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = len;
	while (i--)
	{
		res[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

static size_t	count_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
/*
int	main(void)
{
	int	n = -124;
	char	*res = ft_itoa(n);
	printf("%s\n", res);
}
*/
