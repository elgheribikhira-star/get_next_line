/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-gher <kel-gher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:47:56 by kel-gher          #+#    #+#             */
/*   Updated: 2025/12/21 12:19:29 by kel-gher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*separate_line(char *old_buff)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	if (!old_buff)
		return (NULL);
	while (old_buff[i] && old_buff[i] != '\n')
		i++;
	if (old_buff[i] != '\0')
		i++;
	if (old_buff[i] == '\0')
	{
		free(old_buff);
		return (NULL);
	}
	new_buff = malloc(ft_strlen(old_buff) - i + 1);
	if (!new_buff)
		return (NULL);
	j = 0;
	while (old_buff[i] != '\0')
		new_buff[j++] = old_buff[i++];
	new_buff[j] = '\0';
	free(old_buff);
	return (new_buff);
}

char	*extract_line(char *s)
{
	char	*new;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buff;
	ssize_t		lire;
	char		*extract;

	extract = NULL;
	buff = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_null(&str, buff));
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free_null(&str, buff));
	while (!str || !ft_strchr(str, '\n'))
	{
		lire = read(fd, buff, BUFFER_SIZE);
		if (lire == -1)
			return (free_null(&str, buff));
		if (lire == 0)
			break ;
		buff[lire] = '\0';
		str = ft_strjoin_null(str, buff);
		if (!str)
			return (free_null(&str, buff));
	}
	return (finish_line(&str, buff));
}

char	*free_null(char **str, char *buff)
{
	if (buff)
		free(buff);
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*finish_line(char **str, char *buff)
{
	char	*extract;

	extract = NULL;
	if (*str != NULL)
	{
		extract = extract_line(*str);
		if (!extract)
			return (free_null(str, buff));
		*str = separate_line(*str);
	}
	free(buff);
	return (extract);
}


