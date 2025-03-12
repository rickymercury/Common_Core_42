/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:25:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 12:48:09 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	printf("ft_isascii(%c): %i\n", argv[1][0], ft_isascii(argv[1][0]));
	printf("ft_isascii(200): %i\n", ft_isascii(200));
	return (0);
} */