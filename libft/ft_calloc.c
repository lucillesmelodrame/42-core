/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 18:21:14 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/09 19:54:31 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*tmp;
	size_t	i;

	tmp = malloc(n * size);
	i = 0;
	if (!tmp)
		return (NULL);
	while (i < n * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
/*
int	main(void)
{
	int	*ptr = (int *)ft_calloc(5, sizeof(int));
	if (ptr == NULL)
	{
		printf("Allocation Failed");
		exit(0);
	}
	int	i = 0;
	while (i < 5)
	{
		printf("%d ", ptr[i]);
		i++;
	}
	return (0);
}
*/
