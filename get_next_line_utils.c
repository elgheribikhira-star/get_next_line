/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-gher <kel-gher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:48:00 by kel-gher          #+#    #+#             */
/*   Updated: 2025/12/19 17:54:11 by kel-gher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
static char	*join_when_s1_null(char const *s2)
{
	char	*res;
	size_t	i;

	if (!s2)
		return (NULL);
	res = malloc(ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s2[i] != '\0')
	{
		res[i] = s2[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_null(char const *s1, char const *s2)
{
	char		*res;
	size_t		i;
	size_t		j;

	if (!s2)
		return (NULL);
	if (!s1)
		return (join_when_s1_null(s2));
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
