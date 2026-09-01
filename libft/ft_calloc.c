/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 18:21:14 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 05:34:40 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*tmp;
	size_t	i;

	if (n == 0 || size == 0)
	{
		tmp = malloc(1);
		return (tmp);
	}
	if (n > (size_t)-1 / size)
		return (NULL);
	tmp = malloc(n * size);
	i = 0;
	if (!tmp)
		return (NULL);
	while (i < n * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

#include "testers.h"

int	main(void)
{
	size_t	nmemb_tests[] = {5, 0, 1, 1000};
	size_t	size_tests[] = {sizeof(int), 0, sizeof(char), sizeof(int)};
	int		count = sizeof(nmemb_tests) / sizeof(nmemb_tests[0]);

	for (int i = 0; i < count; i++)
	{
		void	*result = ft_calloc(nmemb_tests[i], size_tests[i]);
		size_t	total = nmemb_tests[i] * size_tests[i];
		int		all_zero = 1;
		int		pass;
		char	*status_str;
		char	*zero_str;

		if (result)
			for (size_t j = 0; j < total; j++)
				if (((unsigned char *)result)[j] != 0)
					all_zero = 0;
		if ((result || total == 0) && all_zero)
			pass = 1;
		else
			pass = 0;
		if (result)
			status_str = "got a buffer";
		else
			status_str = "NULL";
		if (all_zero)
			zero_str = "yep";
		else
			zero_str = "nope";
		if (pass)
			printf(GREEN);
		else
			printf(RED);
		printf("nmemb: %zu | size: %zu | result: %s | all zero: %s\n\n",
			nmemb_tests[i], size_tests[i], status_str, zero_str);
		printf(RESET);
		free(result);
	}
	void	*huge = ft_calloc((size_t)-1, (size_t)-1);
	char	*huge_str;

	if (huge)
		huge_str = "allocated (bug, should be NULL)";
	else
		huge_str = "NULL (good)";
	if (huge == NULL)
		printf(GREEN);
	else
		printf(RED);
	printf("desc: overflow check, nmemb and size both maxed out\n");
	printf("result: %s\n\n", huge_str);
	printf(RESET);
	return (0);
}
