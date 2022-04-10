/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:07:06 by icheri            #+#    #+#             */
/*   Updated: 2022/03/11 20:14:30 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static bool	search_line_break(char *str)
{
	while (*str)
		if (*str++ == '\n')
			return (true);
	return (false);
}

static char	*save_buffer(char *str, char *buffer)
{
	char	*temp;

	if (str)
	{
		temp = str;
		str = ft_strjoin(str, buffer);
		free(temp);
	}
	else
		str = ft_strdup(buffer);
	return (str);
}

static char	*get_line_and_remainder(char **str)
{
	char	*temp;
	size_t	count;
	char	*line;

	if (!(*str))
		return (NULL);
	count = 0;
	while ((*str)[count] != '\n' && (*str)[count])
		count++;
	if (count < ft_strlen(*str))
	{
		temp = *str;
		line = ft_substr(*str, 0, ++count);
		*str = ft_substr(*str, count, ft_strlen(*str));
		free(temp);
	}
	else
	{
		line = *str;
		*str = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			readed;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) *(BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readed = read(fd, buffer, BUFFER_SIZE);
	while (readed > 0)
	{
		buffer[readed] = '\0';
		str = save_buffer(str, buffer);
		if (search_line_break(str))
			break ;
		readed = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (get_line_and_remainder(&str));
}
