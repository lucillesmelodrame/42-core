/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:41:05 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/03 14:31:21 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t n)
{
	unsigned char	*csrc;
	unsigned char	cc;
	size_t			i;

	csrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		cc = (unsigned char )c;
		csrc[i] = cc;
		i++;
	}
	return (src);
}

#include "testers.h"

int	main(void)
{
	t_memset tests[] =
	{
		{"Hello World!", 'a', 0, "n=0, nothing should change"},
		{"Hello World!", 0, 5, "zeroing out first 5 bytes"},
		{"Hello World!", 256, 5, "value over 255, checking the wraparound"},
		{"a", 'o', 1, "tiny 1 byte buffer"}
	};
	int		count = sizeof(tests) / sizeof(tests[0]);
	char 	buf[20] = {0};
	char	abuf[20] = {0};
	for (int i = 0; i < count; i++)
	{
		const char	*input = (const char *)tests[i].s;
		ft_strlcpy(buf, input, sizeof(buf));
		ft_strlcpy(abuf, input, sizeof(abuf));
		char	*result = (char *)ft_memset(buf, tests[i].c, tests[i].n);
		char	*aresult = (char *)memset(abuf, tests[i].c, tests[i].n);
		int		cmp = ft_memcmp(result, aresult, sizeof(buf));
		char	*label = tests[i].label;
		if (cmp == 0)
			printf(GREEN);
		else
			printf(RED);
		printf("input: %s | desc: %s | result: %s | expected: %s | memcmp: %d\n\n", input, label, result, aresult, cmp);
		printf(RESET);
	}
}
