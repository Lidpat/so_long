/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:28:17 by lpalacio          #+#    #+#             */
/*   Updated: 2023/02/28 22:21:08 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*calloc_gnl(size_t count, size_t size)
{
	char	*ptr;
	size_t	max_size_t;

	max_size_t = (size_t) - 1;
	if (size > 0 && count > max_size_t / size)
		return (NULL);
	max_size_t = count * size;
	ptr = malloc (max_size_t);
	if (ptr != NULL)
	{
		while (max_size_t--)
				ptr[max_size_t] = 0;
	}
	return (ptr);
}

size_t	search_newline(const char *s)
{
	size_t	pos;

	pos = 0;
	while (s[pos] != '\n' && s[pos] != 0)
		pos++;
	return (pos);
}

size_t	strlen_gnl(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != 0)
		n ++;
	return (n);
}

char	*strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = strlen_gnl (s1);
	len2 = strlen_gnl (s2);
	str = calloc_gnl (len1 + len2 + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (len2--)
		str[len1 + len2] = s2[len2];
	while (len1--)
		str[len1] = s1[len1];
	return (str);
}

char	*read_nextline(char *aux, int fd, size_t *pos)
{
	ssize_t	rb;
	char	*buff;

	while (*pos == strlen_gnl(aux))
	{
		buff = calloc_gnl (BUFFER_SIZE + 1, sizeof(char));
		if (buff == NULL)
		{	
			free (aux);
			return (NULL);
		}
		rb = read (fd, buff, BUFFER_SIZE);
		if (rb < 0)
		{
			free (aux);
			free (buff);
			return (NULL);
		}
		aux = save_buff (aux, buff);
		if (rb == 0)
			return (aux);
		*pos = search_newline (aux);
	}
	return (aux);
}
