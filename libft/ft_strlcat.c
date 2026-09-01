/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:18:19 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:25:52 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (n <= dest_len)
		dest_len = n;
	if (n == dest_len)
		return (dest_len + src_len);
	if (src_len < n - dest_len)
		ft_memcpy(dest + dest_len, src, src_len + 1);
	else
	{
		ft_memcpy(dest + dest_len, src, n - dest_len - 1);
		dest[n - 1] = '\0';
	}
	return (dest_len + src_len);
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

		ft_strlcat(buf, tests[i].dst, sizeof(buf));
		ft_strlcat(abuf, tests[i].dst, sizeof(abuf));
		size_t	result = ft_strlcat(buf, tests[i].src, tests[i].n);
		size_t	aresult = strlcat(abuf, tests[i].src, tests[i].n);

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
