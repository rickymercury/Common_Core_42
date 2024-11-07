/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:27:35 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/07 15:12:19 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_char(char c)
{
    write(1, &c, 1);
}

int ft_hexlen(unsigned int num)
{
    int length = 0;
    while (num != 0)
    {
        num = num / 16;
        length++;
    }
    return (length);
}

void ft_printhex(unsigned int num, const char format)
{
    if (num >= 16)
    {
        ft_printhex(num / 16, format);
        ft_printhex(num % 16, format);
    }
    else
    {
        if (num <= 9)
            ft_putchar((num + '0'));
        else
        {
            if (format == 'x')
                ft_print_char((num - 10 + 'a'));
            if (format == 'X')
                ft_print_char((num - 10 + 'A'));
        }
    }
}

int ft_print_hexadecimal(unsigned int num, const char format)
{
    if (num == 0)
        return (write(1, "0", 1));
    else
        ft_printhex(num, format);
    return (ft_hexlen(num));
}

/*
TEST HEXADECIMAL

int	main(void)
{
    unsigned int num1 = 0x2A3F;
    unsigned int num2 = 0x0;
    unsigned int num3 = 0x7F1;

    write(1, "Hexadecimal com 'x' (minúsculo): ", 33);
    ft_puthexadecimal(num1, 'x');
    write(1, "\n", 1);

    write(1, "Hexadecimal com 'X' (maiúsculo): ", 34);
    ft_puthexadecimal(num1, 'X');
    write(1, "\n", 1);

    write(1, "Hexadecimal de 0: ", 19);
    ft_puthexadecimal(num2, 'x');
    write(1, "\n", 1);

    write(1, "Hexadecimal de 0x7F1 com 'x': ", 30);
    ft_puthexadecimal(num3, 'x');
    write(1, "\n", 1);

    write(1, "Hexadecimal de 0x7F1 com 'X': ", 30);
    ft_puthexadecimal(num3, 'X');
    write(1, "\n", 1);

    return 0;
}
*/

/*
 * Recursively prints a number in hexadecimal format.
 *
 * The param n is the number to be printed in hexadecimal.
 * The param c Specifies whether the hexadecimal letters should be lowercase ('x') or uppercase ('X').
 *
 * This function recursively converts the given number 'n' into its hexadecimal representation.
 * If 'n' is greater than or equal to 16, the function continues to divide the number, printing the 
 * remainders in reverse order. It uses the ASCII values to print numbers (0-9) and hexadecimal letters 
 * (a-f or A-F) based on the value of 'c'.
 *
 * return the number of characters printed.
 */