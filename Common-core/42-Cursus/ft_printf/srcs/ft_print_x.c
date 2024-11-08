/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:27:35 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 20:26:40 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_hex_rec(unsigned int n, char format)
{
    char hex_digit;

    if (n >= 16)
        print_hex_rec(n / 16, format);
    hex_digit = "0123456789abcdef"[n % 16];
    if (format == 'X' && hex_digit >= 'a' && hex_digit <= 'f')
        hex_digit -= 32;
    ft_print_c(hex_digit);
}

int ft_print_x(unsigned int n, char format)
{
    int count;

    if (n == 0)
        return ft_print_c('0');

    count = 0;
    print_hex_rec(n, format);
    while (n > 0)
    {
        n /= 16;
        count++;
    }

    return (count);
}

