/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:42:59 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:25:21 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = ft_strlen(src);
	if (n >= len + 1)
		ft_memcpy(dest, src, len + 1);
	else if (n != 0)
	{
		ft_memcpy(dest, src, n - 1);
		dest[n - 1] = '\0';
	}
	return (len);
}

#include "testers.h"

int	main(void)
{
	t_strl	tests[] =
	{
		{"", "Hello", 20, "plenty of room, no issues"},
		{"", "Hello", 0, "dstsize 0, shouldnt write anything"},
		{"", "Hello", 3, "dstsize too small, gets cut off"},
		{"", "", 20, "src is empty"},
		{"Existing", "World", 20, "cat: tacking on to existing stuff"},
		{"Existing", "World", 10, "cat: dstsize smaller than combined length"}
	};
	int		count = sizeof(tests) / sizeof(tests[0]);
	char	buf[20];
	char	abuf[20];

	for (int i = 0; i < count; i++)
	{
		char	*label = tests[i].label;
		int		pass;

		ft_strlcpy(buf, tests[i].dst, sizeof(buf));
		ft_strlcpy(abuf, tests[i].dst, sizeof(abuf));
		size_t	result = ft_strlcpy(buf, tests[i].src, tests[i].n);
		size_t	aresult = strlcpy(abuf, tests[i].src, tests[i].n);

		if (result == aresult && ft_strncmp(buf, abuf, 20) == 0)
			pass = 1;
		else
			pass = 0;
		if (pass)
			printf(GREEN);
		else
			printf(RED);
		printf("desc: %s | result buf: %s | expected buf: %s | ret: %zu | expected ret: %zu\n\n",
			label, buf, abuf, result, aresult);
		printf(RESET);
	}
	return (0);
}
