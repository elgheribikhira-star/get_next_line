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
	int			i;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (!ft_strchr(str, '\n'))
		{
			separate_line(buff);
			read(fd, buff, BUFFER_SIZE);
		}
		i++;
	}
}

static	char	*separate_line(char *old_buff)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (old_buff[i] && old_buff[i] != '\n')
		i++;
	new_buff = malloc(ft_strlen(old_buff) - i + 1);
	j = 0;
	while (old_buff[i] != '\0')
	{
		new_buff[j] = old_buff[i];
		i++;
		j++;
	}
	new_buff[j] = '\0';
	return (new_buff);
}