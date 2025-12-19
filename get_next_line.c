/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-gher <kel-gher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:47:56 by kel-gher          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/12/19 17:54:49 by kel-gher         ###   ########.fr       */
=======
/*   Updated: 2025/12/18 17:03:52 by kel-gher         ###   ########.fr       */
>>>>>>> cca610d50b4d78d564fed370753b829a40c29d7e
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

<<<<<<< HEAD
char	*separate_line(char *old_buff)
=======
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
>>>>>>> cca610d50b4d78d564fed370753b829a40c29d7e
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	if (!old_buff)
		return (NULL);
	while (old_buff[i] && old_buff[i] != '\n')
		i++;
<<<<<<< HEAD
	// if (old_buff[i] == '\0')
	// {
	// 	free(old_buff);
	// 	return (NULL);
	// }
=======
	if (old_buff[i] == '\0')
	{
		free(old_buff);
		return (NULL);
	}
>>>>>>> cca610d50b4d78d564fed370753b829a40c29d7e
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

<<<<<<< HEAD
char	*extract_line(char *s)
=======
static char	*extract_line(char *s)
>>>>>>> cca610d50b4d78d564fed370753b829a40c29d7e
{
	char	*new;
	int		i;

	i = 0;

	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
<<<<<<< HEAD
	new = malloc(i + 1);
=======
	new = malloc(ft_strlen(s) - i + 2);
>>>>>>> cca610d50b4d78d564fed370753b829a40c29d7e
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new[i] = s[i];
		i++;
	}
<<<<<<< HEAD
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
	char	*buff;
	ssize_t		lire;
	char	*extract;

	extract = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!str || !ft_strchr(str, '\n'))
	{
		lire = read(fd, buff, BUFFER_SIZE);
		if (lire == -1)
		{
			free(buff);
			return (NULL);
		}
		if (lire == 0)
			break;
		buff[lire] = '\0';
		str = ft_strjoin_null(str, buff);
		if (!str)
		{
			free(buff);
			return (NULL);
		}
	}
	if (str != NULL && str[0] != '\0')
	{
		extract = extract_line(str);
		if (!extract)
		{
			free(buff);
			return (NULL);
		}
		str = separate_line(str);
	}
	free(buff);
	return (extract);
}

=======
	new[i] = '\n';
	i++;
	new[i] = '\0';
	return (new);
}
>>>>>>> cca610d50b4d78d564fed370753b829a40c29d7e
