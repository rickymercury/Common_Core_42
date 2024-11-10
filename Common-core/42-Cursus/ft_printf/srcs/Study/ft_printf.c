/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:51:38 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 20:27:00 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int format_printf(va_list args, const char format)
{
    if (format == 'c')
        return (ft_print_c(va_arg(args, int)));
    else if (format == 's')
        return (ft_print_s(va_arg(args, char *)));
    else if (format == 'p')
        return (ft_print_p(va_arg(args, unsigned long long)));
    else if (format == 'd' || format == 'i')
        return (ft_print_d(va_arg(args, int)));
    else if (format == 'u')
        return (ft_print_u(va_arg(args, unsigned int)));
    else if (format == 'x' || format == 'X')
        return (ft_print_x(va_arg(args, unsigned int), format));
    else if (format == '%')
        return (ft_print_c('%'));
    return (0);
}

int handle_format(va_list args, const char *str, size_t *i)
{
    int len = 0;
    
    if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p' ||
        str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'u' ||
        str[*i] == 'x' || str[*i] == 'X' || str[*i] == '%')
    {
        len = format_printf(args, str[*i]);
    }
    else
    {
        ft_print_c('%');
        ft_print_c(str[*i]);
        len = 2;
    }
    (*i)++;
    return (len);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    size_t i = 0;
    int len = 0;

    if (!format)
        return (-1);

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i])
                len += handle_format(args, format, &i);
        }
        else
        {
            len += ft_print_c(format[i]);
            i++;
        }
    }
    va_end(args);
    return (len);
}
