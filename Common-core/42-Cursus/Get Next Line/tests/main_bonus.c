/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:12:52 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/17 23:38:08 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>

int	main(void)
{
	int		fd1, fd2, fd3;
	char	*line = NULL;
	int		line_counter = 1;

	fd1 = open("./tests/examples/test1", O_RDONLY);
	fd2 = open("./tests/examples/test2", O_RDONLY);
	fd3 = open("./tests/examples/test3", O_RDONLY);

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		perror("Failed to open one or more files");
		return (1);
	}

	while (true)
	{
		line = get_next_line(fd1);
		if (line)
		{
			printf("LINE %d: '%s'\n", line_counter++, line);
			free(line);
		}
		else
			break;

		line = get_next_line(fd2);
		if (line)
		{
			printf("LINE %d: '%s'\n", line_counter++, line);
			free(line);
		}
		else
			break;

		line = get_next_line(fd3);
		if (line)
		{
			printf("LINE %d: '%s'\n", line_counter++, line);
			free(line);
		}
		else
			break;
	}

	printf("----------------------------\n");

	close(fd1);
	close(fd2);
	close(fd3);

	return (0);
}
