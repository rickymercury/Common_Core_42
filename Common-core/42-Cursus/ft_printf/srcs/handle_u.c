/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:28:44 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/26 08:48:55 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_u(unsigned int n)
{
	char			*str;
	int				u;
	unsigned int	num;

	num = n;
	u = ft_unsigned_len(num);
	str = malloc((u + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[u] = '\0';
	while (num > 0)
	{
		str[--u] = (num % 10) + '0';
		num /= 10;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}