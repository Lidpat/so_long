/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:42:52 by lpalacio          #+#    #+#             */
/*   Updated: 2023/02/28 22:08:11 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*calloc_gnl(size_t count, size_t size);
size_t	search_newline(const char *s);
size_t	strlen_gnl(const char *s);
char	*strjoin_gnl(char const *s1, char const *s2);
char	*assign_line(char *rest, size_t pos);
char	*assign_rest(char *rest, size_t pos);
char	*last_line(char *rest);
char	*read_nextline(char *aux, int fd, size_t *pos);
char	*save_buff(char *rest, char *buff);

#endif
