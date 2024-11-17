# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char *ft_strchr(const char *s, int c)
{
    int i;
    char *str;

    i = 0;
    str = (char *)s;
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            return (str + i);
        i++;
    }
    if ((char)c == '\0')
        return (str + i);
    return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
	return (str);
}

char	*read_from_fd(int fd, char *str)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	return (ft_free(&str));
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			str = ft_strjoin(str, buffer);
		}
	}
	free(buffer);
	if (bytes_read == -1)
			return (ft_free(&str));
	return (str);
}

char	*get_line(char *text)
{
	int		i;
	char	*line;

	i = 0;
	if (text[i] == '\0')
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == '\0')
		line = malloc(i + 1);
	else //   \n\0
		line = malloc(i + 2);
	if (text[i] == '\n')
		i++;
	// line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*remain_text(char *text)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (text[i] != '\0' && text[i] != '\n')
		i++;
	if (text[i] == '\0' || text[i + 1] == '\0')
	{
		free(text);
		return (NULL);
	}
	remainder = (char *)malloc((ft_strlen(text) - i) * sizeof(char));
	if (!remainder)
		return (NULL);
	i++;
	while (text[i])
		remainder[j++] = text[i++];
	remainder[j] = '\0';
	free(text);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*read_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_line)
	{
		read_line = malloc(1);
		read_line[0] = '\0';
	}
	read_line = read_from_fd(fd, read_line);
	if (!read_line)
		return (NULL);
	line = get_line(read_line);
	read_line = remain_text(read_line);
	return (line);
}

int	main(void)
{
	int		fd = 0;
	char	*line = NULL;

	fd = open("test1.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	if (fd < 0)
	{
		printf("Error: failed to open file\n");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	if (line == NULL)
	{
		printf("End fo file reached\n");
	}
	close(fd);
	return (0);
}