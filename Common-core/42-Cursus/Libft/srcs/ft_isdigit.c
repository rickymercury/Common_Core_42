/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:30:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/12 12:48:36 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	printf("ft_isdigit(%c): %i\n", argv[1][0], ft_isdigit(argv[1][0]));
	return (0);
} */