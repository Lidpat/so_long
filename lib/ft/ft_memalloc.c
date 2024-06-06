/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:11:28 by lpalacio          #+#    #+#             */
/*   Updated: 2022/09/25 18:32:47 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc (count * size);
	if (ptr != NULL)
		ft_bzero (ptr, count * size);
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	n;
	size_t	check;

	n = ft_strlen (s1) + 1;
	str = (char *)malloc (n * sizeof(char));
	if (str != NULL)
	{	
		check = ft_strlcpy(str, s1, n);
		if (check >= n)
		{
			free (str);
			return (NULL);
		}
	}
	return (str);
}
