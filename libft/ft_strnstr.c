/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:02:36 by sonfong           #+#    #+#             */
/*   Updated: 2026/07/29 16:53:12 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(char *src, char *find, int n)
{
	if (*find == '\0')
		return (src);
	while (*src)
	{
		while (*find && *find < n)
		{
			if (*find == *src)
				return (find);
			find++;
		}
		src++;
	}
	return (0);
}
