#ifndef TESTERS_H
# define TESTERS_H

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define RESET   "\033[0m"

# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <bsd/string.h>

typedef struct s_memchr
{
	const void 	*src;
	int 		c;
	size_t 		n;
	char 		*label;
}	t_memchr;

typedef struct s_memset
{
	void	*s;
	int		c;
	size_t	n;
	char	*label;
}	t_memset;

typedef struct s_bzero
{
	void	*s;
	size_t	n;
	char	*label;
}	t_bzero;

typedef struct s_memmove
{
	void		*dst;
	const void	*src;
	size_t		n;
	char		*label;
}	t_memmove;

typedef struct s_memcmp
{
	const void 	*s1;
	const void 	*s2;
	size_t		n;
	char		*label;
}	t_memcmp;

typedef struct s_memcpy
{
	void	*dst;
	const void	*src;
	size_t	n;
	char	*label;
}	t_memcpy;

typedef struct s_strchr
{
	char	*s;
	int		c;
	char	*label;
}	t_strchr;

typedef struct s_strncmp
{
	char	*s1;
	char	*s2;
	size_t	n;
	char	*label;
}	t_strncmp;

typedef struct s_strnstr
{
	char	*big;
	char	*little;
	size_t	n;
	char	*label;
}	t_strnstr;

typedef struct s_strl
{
	char	*dst;
	char	*src;
	size_t	n;
	char	*label;
}	t_strl;

typedef struct s_substr
{
	char			*s;
	unsigned int	start;
	size_t			len;
	char			*label;
}	t_substr;

typedef struct s_strjoin_test
{
	char	*s1;
	char	*s2;
	char	*label;
}	t_strjoin_test;

typedef struct s_strtrim
{
	char	*s1;
	char	*set;
	char	*label;
}	t_strtrim;

typedef struct s_split
{
	char	*s;
	char	c;
	char	*label;
}	t_split;

#endif
