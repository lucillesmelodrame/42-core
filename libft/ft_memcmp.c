/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:58:46 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/03 13:51:43 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

#include "testers.h"

int	main(void)
{
	t_memcmp	tests[] =
	{
		{"Hello", "Hello", 5, "same buffers"},
		{"Hello", "Hello", 0, "n=0, should always be 0"},
		{"Hello", "Hellp", 5, "only last byte differs"},
		{"Xello", "Hello", 5, "only first byte differs"},
		{"Hel\0lo", "Hel\0lp", 6, "stuff differs after a null byte"},
		{"Hello!!!", "Hello???", 5, "differs after n, should still say equal"},
		{"Apple", "Banana", 5, "s1 comes before s2"},
		{"Banana", "Apple", 5, "s1 comes after s2"}
	};
	int	count = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < count; i++)
	{
		const char	*s1 = (const char *)tests[i].s1;
		const char	*s2 = (const char *)tests[i].s2;
		char		*label = tests[i].label;
		int			result = ft_memcmp(s1, s2, tests[i].n);
		int			aresult = memcmp(s1, s2, tests[i].n);
		int			pass;

		if (result == 0 && aresult == 0)
			pass = 1;
		else if (result > 0 && aresult > 0)
			pass = 1;
		else if (result < 0 && aresult < 0)
			pass = 1;
		else
			pass = 0;
		if (pass)
			printf(GREEN);
		else
			printf(RED);
		printf("desc: %s | s1: %s | s2: %s | result: %d | expected: %d\n\n",
			label, s1, s2, result, aresult);
		printf(RESET);
	}
	return (0);
}
