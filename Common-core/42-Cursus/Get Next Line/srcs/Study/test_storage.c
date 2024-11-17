
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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (size <= start || size == 0)
		len = 0;
	else if (len > size - start)
		len = size - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (len > 0 && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	return (str);
}


/* 
   1) This function is responsible for reading data from a file descriptor (`fd`) and storing the result in a dynamically allocated buffer. 
      It uses a temporary buffer to read data from the file in chunks, and it continues reading until either a newline character (`\n`) is found or the end of the file is reached. 
      The function performs the following tasks:
   
      - It allocates memory for a temporary buffer (`temp_buffer`) that will hold a chunk of data read from the file.
      - It reads from the file using the `read` system call in a loop, storing the data in `temp_buffer`.
      - After each read, if data is successfully retrieved (i.e., `bytes_read > 0`), the function appends this data to the `buffer` using `ft_strjoin`.
      - The reading loop continues until either a newline character (`\n`) is found in the temporary buffer or the end of the file is reached (indicated by `bytes_read == 0`).
      - If an error occurs during the `read` call (i.e., `bytes_read == -1`), the function frees any memory previously allocated for `buffer` and returns `NULL`.
      - Once all relevant data has been read, the function frees the temporary buffer (`temp_buffer`) and returns the updated `buffer`, which contains the accumulated data from the file up to the point of a newline or EOF.

      If `read` reads data successfully, the function returns the updated `buffer`. If an error occurs or memory allocation fails, it ensures proper memory cleanup by freeing the allocated `buffer` and returning `NULL`.

      Parameters:
      - `fd`: The file descriptor from which the data is read.
      - `buffer`: A pointer to the buffer where the data will be accumulated as it is read from the file.

      Return:
      - The updated `buffer` containing the data read so far, or `NULL` if an error occurs.
   
      The function handles reading from the file in chunks and accumulates the data until a line is completed. */

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


/* 2) This function is responsible for extracting a complete line of text from the buffer string.
      It searches for the first occurrence of the newline character (`\n`) and returns a new string containing all the characters
      from the beginning of the buffer up to and including the newline character. The function works as follows:

      - The function searches for the first occurrence of the newline character (`\n`) within the `buffer` using `ft_strchr`.
      - If a newline character is found, the function calculates the length of the line by determining the distance from the start of the buffer to the `\n` character.
      - The function then uses `ft_substr` to create a new string, `line`, containing all characters from the beginning of `buffer` up to and including the newline.
      - If `ft_substr` fails to allocate memory or return a valid string, the function returns `NULL`.
      - If successful, it returns the newly allocated string (`line`), which contains the full line from the buffer.

      Parameters:
      - `buffer`: The string from which a line is to be extracted. It is assumed that this string contains at least one newline character or is empty.

      Return:
      - A new string containing the line from the `buffer` up to and including the newline character (`\n`), or `NULL` if an error occurs or no newline is found.

      This function is useful for extracting lines of text from a buffer when reading from a file or stream. */

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


/* 3) This function is responsible for cleaning up the temporary buffer after reading a complete line. 
      It ensures that only the remaining data (if any) after a newline character (`\n`) is kept in the buffer for future reads.
      The function works as follows:

      - First, it searches for the newline character (`\n`) within the `buffer` using `ft_strchr`. 
      - If no newline character is found, the entire buffer is considered to be consumed, and the memory for the buffer is freed using `ft_free`. It then returns `NULL`, signaling that no more data is left.
      - If a newline is found, it calculates the length of the data up to and including the newline character.
      - It checks if there is any remaining data after the newline. If there isn't, it frees the memory and returns `NULL`, indicating that the buffer has been fully processed.
      - If there is data after the newline, it uses `ft_substr` to create a new string containing only the data after the newline, which will be kept for the next read.
      - The original buffer is freed to avoid memory leaks.
      - If the memory allocation for the new string fails, the function returns `NULL`.

      Parameters:
      - `buffer`: The string holding the current data, which is either partially or fully processed, and may contain a newline character.

      Return:
      - A new string containing the remaining data after the newline character, or `NULL` if no data remains or if memory allocation fails.

      This function is useful for cleaning up the buffer after a line has been read and preparing it for further reads in the case where more data is available. */

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


/* 4) This function is responsible for reading the next line of text from a file descriptor (`fd`) and 
      returning a new string that contains this line.

      The function works as follows:

      - It uses a static variable, `buffer`, to retain data between successive calls. This static variable allows the function 
        to remember the state across different invocations, which is necessary when reading lines from a file incrementally.
      - If the `fd` is invalid (less than 0) or the `BUFFER_SIZE` is less than or equal to 0, the function immediately returns `NULL`.
      - If `buffer` doesn't contain a newline (`\n`) or is empty (NULL), the function calls `read_from_fd` to read more data from the file descriptor into the `buffer`.
      - After reading, the function uses `get_line` to extract the next line from the `buffer`. `get_line` finds the first newline character (`\n`) and returns a new string containing all characters up to and including that newline.
      - If the `get_line` function fails (e.g., if no newline is found or memory allocation fails), the function frees the `buffer` and returns `NULL`.
      - Once the line is extracted, the function calls `clean_buffer` to remove the extracted line from `buffer`. If there is any remaining data in `buffer`, it will be retained for the next call.
      - Finally, the function returns the newly created line string containing the next line of text read from the file.

      Parameters:
      - `fd`: The file descriptor from which to read data (typically a file or stdin).
   
      Return:
      - A string containing the next line of text from the file descriptor, or `NULL` if an error occurs or the end of the file is reached.

      The function is designed to read a file line by line, maintaining a buffer between calls to ensure that data is not lost between successive reads. */

char	*get_next_line(int fd)
{
	static char	*buffer = {0}; // initially points to NULL (or zero)*/
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((buffer && !ft_strchr(buffer, '\n')) || !buffer)
		buffer = read_from_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	if (!line)
		return (ft_free(&buffer));
	buffer = clean_buffer(buffer);
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