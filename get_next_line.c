/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-gher <kel-gher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:47:56 by kel-gher          #+#    #+#             */
/*   Updated: 2025/12/17 16:37:54 by kel-gher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char	*buff;
	size_t		line;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	line = 0;
	while (!ft_strchr(str, '\n'))
	{
		line += read(fd, buff, BUFFER_SIZE);
		separate_line(str);
	}
	return (line);
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
