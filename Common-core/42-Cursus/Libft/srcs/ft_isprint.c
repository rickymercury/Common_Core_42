/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:40:20 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 12:49:05 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		printf("ft_isprint('%c'): %i\n", argv[i][0], ft_isprint(argv[i][0]));
	}
	return (0);
} */