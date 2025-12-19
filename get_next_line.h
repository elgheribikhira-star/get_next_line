/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-gher <kel-gher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:47:53 by kel-gher          #+#    #+#             */
/*   Updated: 2025/12/19 17:56:24 by kel-gher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_null(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);

#endif