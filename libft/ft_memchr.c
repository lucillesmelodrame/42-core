/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:59:33 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:33:19 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*csrc;
	size_t			i;

	csrc = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		if ((unsigned char)c == csrc[i])
			return (&csrc[i]);
		i++;
	}
	return (NULL);
}

#include "testers.h"

char	*safe_str(char *ptr)
{
	if (ptr == NULL)
		return ("NULL");
	return (ptr);
}

int	main(void)
{
	t_memchr tests[] =
	{
		{"Hello World!", 'o', 6, "find the o in first 6 bytes"},
		{"Hello World!", 0, 13, "find the null term at the end"},
		{"Hello World!", 'a', 6, "a isnt even in here"},
		{"Hello World!", ' ', 6, "find space in first 6 bytes, if it counts"},
		{"Hello World!", 'o', 12, "should still grab first o"},
		{"Hello World!", 'o' + 256, 12, "c way out of char range, does cast work"},
		{"", 0, 1, "empty string, just the null byte"},
		{"", 'a', 1, "empty string, a not in there obviously"}
	};
	int	count = sizeof(tests) / sizeof(tests[0]);
	for (int i = 0; i < count; i++)
	{
		char *input = (char *)tests[i].src;
		char *result = (char *)ft_memchr(tests[i].src, tests[i].c, tests[i].n);
		char *aresult = (char *)memchr(tests[i].src, tests[i].c, tests[i].n);
		char *label = tests[i].label;
		if (result == aresult)
			printf(GREEN);
		else
			printf(RED);
		printf("input: %s | desc: %s | result: %s | expected: %s\n\n", input, label, safe_str(result), safe_str(aresult));
		printf(RESET);
	}
	printf(RED "note: the empty string printed is a pointer to a byte which value is '\\0'" RESET);
	return (0);
}
