/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-gher <kel-gher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:47:56 by kel-gher          #+#    #+#             */
/*   Updated: 2025/12/18 17:03:52 by kel-gher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char	*buff;
	size_t		lire;
	char	*extract;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	lire = 0;
	while (!str ||!ft_strchr(str, '\n'))
	{
		lire = read(fd, buff, BUFFER_SIZE);
		buff[lire] = '\0';
		str = ft_strjoin(str, buff);
	}
	extract = (char *)extract_line(str);
	str = separate_line(str);
	return (extract);
}

static	char	*separate_line(char *old_buff)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (old_buff[i] && old_buff[i] != '\n')
		i++;
	if (old_buff[i] == '\0')
	{
		free(old_buff);
		return (NULL);
	}
	new_buff = malloc(ft_strlen(old_buff) - i + 1);
	if (!new_buff)
		return (NULL);
	i++;
	j = 0;
	while (old_buff[i] != '\0')
	{
		new_buff[j] = old_buff[i];
		i++;
		j++;
	}
	new_buff[j] = '\0';
	free(old_buff);
	return (new_buff);
}

static char	*extract_line(char *s)
{
	char	*new;
	int		i;

	i = 0;

	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	new = malloc(ft_strlen(s) - i + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\n';
	i++;
	new[i] = '\0';
	return (new);
}
