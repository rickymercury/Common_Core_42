/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:50:30 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 20:26:23 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t p_digits(unsigned long long n)
{
    size_t digits;

	digits = 0;
    if (n == 0)
        return (1);
    while (n != 0)
    {
        n /= 16;
        digits++;
    }
    return (digits);
}

void print_ptr_rec(unsigned long long ptr)
{
    char hex_digit;

    if (ptr >= 16)
        print_ptr_rec(ptr / 16);
    hex_digit = "0123456789abcdef"[ptr % 16];
    ft_print_c(hex_digit);
}

int ft_print_p(unsigned long long ptr)
{
    int len = 0;

    if (ptr == 0)
        return (write(1, "(nil)", 5));
    len = write(1, "0x", 2);
    print_ptr_rec(ptr);
    len += p_digits(ptr);
    return (len);
}

