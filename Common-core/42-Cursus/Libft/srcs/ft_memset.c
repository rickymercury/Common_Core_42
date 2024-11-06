/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:45:02 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/05 14:21:28 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)ptr)[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}

/*
int		main(int argc, const char *argv[])
{
	void	*mem;
	int		arg;

	if (!(mem = malloc(sizeof(*mem) * 15)) || argc == 1)
		return (0);

	ft_memset(mem, 'j', 15);

	if ((arg = atoi(argv[1])) == 1)
	{
		if (mem != ft_memset(mem, 'c', 5))
			write(1, "mem's address was not returned\n", 31);
		write(1, mem, 15);
		write(1, "\n", 1);
	}
	else if (arg == 2)
	{
		if (mem != ft_memset(mem, 'c', 14))
			write(1, "mem's address was not returned\n", 31);
		write(1, mem, 15);
		write(1, "\n", 1);
	}
	else if (arg == 3)
	{
		if (mem != ft_memset(mem, 'w', 6))
			write(1, "mem's address was not returned\n", 31);
		write(1, mem, 15);
		write(1, "\n", 1);
	}
	else if (arg == 4)
	{
		if (mem != ft_memset(mem, 'a', 1))
			write(1, "mem's address was not returned\n", 31);
		write(1, mem, 15);
		write(1, "\n", 1);
	}

	free(mem);
	return (0);
}
*/

/*
OUTPUT: 

sh-5.2$ cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_memset.c -o ft_memset && for i in {1..5}; do ./ft_memset $i; done
cccccjjjjjjjjjj
ccccccccccccccj
wwwwwwjjjjjjjjj
ajjjjjjjjjjjjjj
*/