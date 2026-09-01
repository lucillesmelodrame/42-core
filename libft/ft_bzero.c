/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:13:24 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:31:42 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*cs;
	size_t			i;

	cs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		cs[i] = 0;
		i++;
	}
}
#include "testers.h"

int	main(void)
{
	t_bzero	tests[] =
	{
		{"Hello", 0, "n=0, buffer stays the same"},
		{"Hello", 5, "wipe the whole thing"},
		{"H", 1, "just 1 byte"},
		{"\0\0\0\0\0", 5, "already all zeros, shouldnt break anything"}
	};
	int		count = sizeof(tests) / sizeof(tests[0]);
	char	buf[20];
	char	abuf[20];

	for (int i = 0; i < count; i++)
	{
		const char	*input = (const char *)tests[i].s;
		char		*label = tests[i].label;

		ft_strlcpy(buf, input, sizeof(buf));
		ft_strlcpy(abuf, input, sizeof(abuf));
		ft_bzero(buf, tests[i].n);
		bzero(abuf, tests[i].n);
		int	cmp = ft_memcmp(buf, abuf, sizeof(buf));

		if (cmp == 0)
			printf(GREEN);
		else
			printf(RED);
		printf("desc: %s | memcmp: %d\n\n", label, cmp);
		printf(RESET);
	}
	return (0);
}
