/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:50:30 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 19:49:11 by rickymercur      ###   ########.fr       */
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
    ft_putchar(hex_digit);
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

/*
int	ft_print_p(unsigned long long ptr)
{
	int		len;
	char	*hex_chars = "0123456789abcdef";
    unsigned long long temp;
    int hex_len;
    int i;
    
	len = 0;
	if (ptr == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len += write(1, "0x", 2);
	temp = ptr;
	hex_len = 0;
	while (temp != 0)
	{
		hex_len++;
		temp /= 16;
	}
	char buffer[hex_len];
	i = hex_len - 1;
	while (ptr != 0)
	{
		buffer[i] = hex_chars[ptr % 16];
		ptr /= 16;
		i--;
	}
	len += write(1, buffer, hex_len);
	return (len);
}
*/


/*
WITHOUT RECURSION

int ft_print_p(unsigned long long ptr)
{
	unsigned long long divisor;
    int len = 0;
    char hex_digit;

    if (ptr == 0)
        return write(1, "(nil)", 5);
    len = write(1, "0x", 2);
    divisor = 1;
    while (ptr / divisor >= 16)
        divisor *= 16;
    while (divisor > 0)
    {
        hex_digit = "0123456789abcdef"[(ptr / divisor) % 16];
        ft_putchar(hex_digit);
        ptr = ptr % divisor;
        divisor /= 16;
        len++;
    }
    return (len);
}
*/

/*
 * Prints a memory address (pointer) in hexadecimal format.
 *
 * The param ptr The memory address (pointer) to be printed.
 *
 * This function prints a pointer in hexadecimal format, prefixed with "0x". If the pointer is NULL 
 * (i.e., ptr == 0), it prints "(nil)" to indicate a null pointer. For non-null pointers, it converts 
 * the pointer to hexadecimal and prints the result prefixed with "0x".
 *
 * return the total number of characters printed, including the "0x" prefix.
 */