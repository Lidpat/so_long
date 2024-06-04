/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:26:25 by lpalacio          #+#    #+#             */
/*   Updated: 2023/02/28 22:23:36 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_buff(char *rest, char *buff)
{
	char	*aux;

	aux = strjoin_gnl(rest, buff);
	free(rest);
	free(buff);
	if (aux == NULL)
		return (NULL);
	return (aux);
}

char	*read_buff(int fd)
{
	char	*buff;
	ssize_t	rb;

	buff = calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (buff == NULL)
		return (NULL);
	rb = read(fd, buff, BUFFER_SIZE);
	if (rb <= 0)
	{
		free (buff);
		return (NULL);
	}
	return (buff);
}

char	*assign_line(char *rest, size_t pos)
{
	size_t	len;
	char	*str;

	if (rest[pos] == 0)
		len = pos;
	else
		len = pos + 1;
	str = calloc_gnl(len + 1, sizeof(char));
	if (str == NULL)
	{
		free (rest);
		return (NULL);
	}
	while (len--)
		str[len] = rest[len];
	return (str);
}

char	*assign_rest(char *rest, size_t pos)
{
	char	*aux;

	if (rest[pos] == 0)
		aux = calloc_gnl(1, sizeof(char));
	else
		aux = strjoin_gnl(rest + pos + 1, "");
	free (rest);
	return (aux);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;
	size_t		pos;	

	if (!((fd == 0 || fd > 2) && BUFFER_SIZE > 0))
		return (NULL);
	if (!rest || rest[0] == 0)
	{
		if (rest)
			free (rest);
		rest = read_buff(fd);
		if (rest == NULL)
			return (NULL);
	}
	pos = search_newline(rest);
	rest = read_nextline (rest, fd, &pos);
	if (rest != NULL)
		line = assign_line (rest, pos);
	if (rest == NULL || line == NULL)
		return (NULL);
	rest = assign_rest (rest, pos);
	if (rest != NULL)
		return (line);
	free (line);
	return (NULL);
}
