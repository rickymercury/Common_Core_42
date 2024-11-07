/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:50:30 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/07 15:01:13 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countptr(unsigned long long prt)
{
	int	count;

	count = 0;
	while (prt != 0)
	{
		count++;
		prt = prt / 16;
	}
	return (count);
}

int	ft_printptr(unsigned long long prt)
{
	if (prt >= 16)
	{
		ft_printptr(prt / 16);
		ft_printptr(prt % 16);
	}
	else
	{
		if (prt <= 9)
			ft_putchar(prt + 48);
		else
			ft_putchar(prt - 10 + 'a');
	}
	return (ft_countptr(prt));
}

int	ft_print_pointer(unsigned long long ptr)
{
	int		len;

	len = 0;
	if (ptr == 0)
	{
		len += write (1, "(nil)", 5);
		return (len);
	}
	len = write (1, "0x", 2);
	len += ft_printptr(ptr);
	return (len);
}

/*
int	ft_print_pointer(unsigned long long ptr)
{
	int		len = 0;
	char	*hex_chars = "0123456789abcdef";
    unsigned long long temp;
    int hex_len;
    int i;

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
#include <stdio.h>

int main(void)
{
    unsigned long long ptr1 = 0;
    unsigned long long ptr2 = 0x1234abcd;
    unsigned long long ptr3 = 0xFFFFFFFFFFFFFFFF;

    printf("Output para ptr1 (0): ");
    ft_print_pointer(ptr1);
    printf("\n");

    printf("Output para ptr2 (0x1234abcd): ");
    ft_print_pointer(ptr2);
    printf("\n");

    printf("Output para ptr3 (0xFFFFFFFFFFFFFFFF): ");
    ft_print_pointer(ptr3);
    printf("\n");

    return 0;
}
*/


/*
PROTOTYPE: 

int	ft_put_ptr(uintptr_t ptr)
{
	int		count;
	char	*chars;

	count = 0;
	chars = "0123456789abcdef";
	if (ptr >= 16)
	{
		count += ft_put_ptr(ptr / 16);
		count += ft_put_ptr(ptr % 16);
	}
	else
		count += ft_print_c(chars[ptr]);
	if (count < 0)
		return (-1);
	return (count);
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