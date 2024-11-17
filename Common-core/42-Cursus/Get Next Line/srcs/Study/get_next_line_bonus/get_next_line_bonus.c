/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:03:58 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/17 20:25:13 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_from_fd(int fd, char *buffer)
{
	int		bytes_read;
	char	*temp_buffer;

	bytes_read = 1;
	temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buffer)
		return (ft_free(&buffer));
	temp_buffer[0] = '\0';
	while (bytes_read > 0 && !ft_strchr(temp_buffer, '\n'))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			temp_buffer[bytes_read] = '\0';
			buffer = ft_strjoin(buffer, temp_buffer);
		}
	}
	free(temp_buffer);
	if (bytes_read == -1)
		return (ft_free(&buffer));
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(buffer, '\n');
	len = (ptr - buffer) + 1;
	line = ft_substr(buffer, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*clean_buffer(char *buffer)
{
	char	*new_buffer;
	char	*ptr;
	int		len;

	ptr = ft_strchr(buffer, '\n');
	if (!ptr)
	{
		new_buffer = NULL;
		return (ft_free(&buffer));
	}
	else
		len = (ptr - buffer) + 1;
	if (!buffer[len])
		return (ft_free(&buffer));
	new_buffer = ft_substr(buffer, len, ft_strlen(buffer) - len);
	ft_free(&buffer);
	if (!new_buffer)
		return (NULL);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if ((buffer[fd] && !ft_strchr(buffer[fd], '\n')) || !buffer[fd])
		buffer[fd] = read_from_fd(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	if (!line)
		return (ft_free(&buffer[fd]));
	buffer[fd] = clean_buffer(buffer[fd]);
	return(line);
}