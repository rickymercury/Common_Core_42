/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:27:35 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/07 20:32:21 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hex_len(unsigned int num)
{
    int len;

    len = 0;
    while (num != 0)
    {
        num = num / 16;
        len++;
    }
    return (len);
}

void ft_recursive_print_hex(unsigned int num, const char hex_format)
{
    if (num >= 16)
    {
        ft_recursive_print_hex(num / 16, hex_format);
        ft_recursive_print_hex(num % 16, hex_format);
    }
    else
    {
        if (num <= 9)
            ft_print_c((num + '0'));
        else
        {
            if (hex_format == 'x')
                ft_print_c((num - 10 + 'a'));
            if (hex_format == 'X')
                ft_print_c((num - 10 + 'A'));
        }
    }
}

int ft_print_x(unsigned int num, const char hex_format)
{
    if (num == 0)
        return (write(1, "0", 1));
    else
        ft_recursive_print_hex(num, hex_format);
    return (ft_hex_len(num));
}