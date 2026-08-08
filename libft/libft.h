/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:16:03 by sonfong           #+#    #+#             */
/*   Updated: 2026/08/07 10:30:41 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *src, int c, size_t n);
char	*ft_strchr(char	*src, int c);
char	*ft_strlcat(char *dest, const char *src, size_t n);
char	*ft_strlcpy(char *dest, const char *src, size_t n);
char	ft_toupper(char c);
char	ft_tolower(char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int	ft_strcmp(char *s1, char *s2, size_t n);
void	*ft_memchr(const void *src, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(char *src, char *find, int c);
int	ft_atoi(const char *nptr);
void	*ft_memcpy(void	*dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
