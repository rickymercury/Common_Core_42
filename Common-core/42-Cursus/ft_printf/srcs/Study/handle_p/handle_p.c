/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:54:47 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/25 21:31:43 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexapointer(unsigned long int n)
{
	size_t		len;
	size_t		i;
	char		buffer[42];
	char		*hex;

	hex = "0123456789abcdef";
	i = 0;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = 2;
	write (1, "0x", 2);
	while (n)
	{
		buffer[i] = hex[n % 16];
		n /= 16;
		i++;
		len++;
	}
	while (i--)
		ft_putchar_fd(buffer[i], 1);
	return (len);
}