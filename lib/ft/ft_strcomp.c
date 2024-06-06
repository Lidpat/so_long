/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcomp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:23:21 by lpalacio          #+#    #+#             */
/*   Updated: 2022/09/24 18:29:34 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*pos;

	pos = (char *)s;
	while (*pos != 0)
	{
		if (*pos == (char)c)
			return (pos);
		pos++;
	}
	if (*pos == (char)c)
		return (pos);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*pos;

	pos = (char *)s + ft_strlen(s);
	while (pos >= s)
	{
		if (*pos == (char)c)
			return (pos);
		pos--;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*f1;
	unsigned char	*f2;

	f1 = (unsigned char *)s1;
	f2 = (unsigned char *)s2;
	i = 0;
	while ((i < n) && ((f1[i] != 0) || (f2[i] != 0)))
	{
		if (f1[i] != f2[i])
			return (f1[i] - f2[i]);
		i++;
	}
	return (0);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*comp;
	unsigned char	cc;

	comp = (unsigned char *)s;
	cc = (unsigned char)c;
	if (n != 0)
	{
		while (n--)
		{
			if (*comp == cc)
				return (comp);
			comp++;
		}
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return ((int)*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
