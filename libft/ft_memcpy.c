/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:17:42 by sonfong           #+#    #+#             */
/*   Updated: 2026/07/29 17:51:57 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_memcpy(const void *dest, const void *src, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	int	i;

	p1 = (const unsigned char *)dest;
	p2 = (const unsigned char *)src;
	i = 0;
	if (n == 0)
		return (0);
	while (p1[i] && i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (p1);
}
