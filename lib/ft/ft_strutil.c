/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:58:57 by lpalacio          #+#    #+#             */
/*   Updated: 2022/09/23 19:41:52 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*buff;
	const char	*src_b;

	buff = (char *)dst;
	src_b = (const char *)src;
	if (n > 0 && (dst != 0 || src != 0))
	{	
		while (n--)
			buff[n] = src_b[n];
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*src_buff;
	char		*dst_buff;
	size_t		i;

	i = len;
	dst_buff = (char *)dst;
	src_buff = (const char *)src;
	if (dst_buff == NULL && src_buff == NULL)
		return (NULL);
	else if (len > 0)
	{
		if (dst < src && (dst + len) > src)
		{
			while (len--)
				dst_buff[i - len - 1] = src_buff[i - len - 1];
		}
		else if (dst != src)
		{
			while (len--)
				dst_buff[len] = src_buff[len];
		}
	}	
	return (dst);
}
