/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:17:42 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:31:16 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;

	cdest = (char *)dest;
	csrc = (char *)src;
	if (n == 0 || (!src && !dest))
		return (dest);
	while (n--)
		cdest[n] = csrc[n];
	return (dest);
}

#include "testers.h"

int	main(void)
{
	t_memcpy	tests[] =
	{
		{"Hello", "World!", 6, "dest gets fully overwritten"},
		{"Hello", "World!", 0, "n=0, dest untouched"},
		{"Hello", "World!", 1, "just 1 byte over"},
		{"Hello", "", 1, "copying the null term"},
		{"Hello", "Wor\0ld", 7, "null byte in the middle of src"},
		{"Hel\0lo", "World", 6, "null byte in the middle of dest"},
		{"Hello", "Hi!", 3, "src is shorter than dest"},
		{"Hi!", "Hello", 5, "src is longer than dest"}
	};
	int		count = sizeof(tests) / sizeof(tests[0]);
	char	buf[20];
	char	abuf[20];

	for (int i = 0; i < count; i++)
	{
		char		*dest = (char *)tests[i].dst;
		const char	*src = (const char *)tests[i].src;
		char		*label = tests[i].label;

		ft_strlcpy(buf, dest, sizeof(buf));
		ft_strlcpy(abuf, dest, sizeof(abuf));
		char	*result = (char *)ft_memcpy(buf, src, tests[i].n);
		char	*aresult = (char *)memcpy(abuf, src, tests[i].n);
		int		cmp = ft_memcmp(buf, abuf, sizeof(buf));

		if (cmp == 0)
			printf(GREEN);
		else
			printf(RED);
		printf("desc: %s | src: %s | result: %s | expected: %s | memcmp: %d\n\n",
			label, src, result, aresult, cmp);
		printf(RESET);
	}
	return (0);
}
