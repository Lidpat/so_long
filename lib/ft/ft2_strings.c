/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:08:31 by lpalacio          #+#    #+#             */
/*   Updated: 2022/09/27 19:23:50 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (len == 0 || start >= ft_strlen(s) + 1)
		str = (char *)ft_calloc (1, sizeof(char));
	else if ((start <= ft_strlen (s)) && (len + start) >= ft_strlen (s))
		str = (char *)ft_strdup (s + start);
	else
	{
		str = (char *)ft_calloc (len + 1, sizeof(char));
		if (str != NULL)
			ft_strlcpy (str, s + start, len + 1);
	}
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen (s1);
	len2 = ft_strlen (s2);
	str = (char *)ft_calloc (len1 + len2 + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcpy(str + len1, s2, len2 + 1);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] != 0 && (ft_strchr(set, s1[i]) != NULL))
		i++;
	while (j > i && (ft_strchr(set, s1[j]) != NULL))
		j--;
	len = j - i + 1;
	str = ft_substr (s1, i, len);
	if (str == NULL)
		return (NULL);
	return (str);
}
