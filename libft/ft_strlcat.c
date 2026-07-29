/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:18:19 by sonfong           #+#    #+#             */
/*   Updated: 2026/07/28 16:51:20 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlcat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while (dest[i])
		i++;
	while (j < n && src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	while (j < n)
		dest[j] = '\0';
	return (dest);
}
