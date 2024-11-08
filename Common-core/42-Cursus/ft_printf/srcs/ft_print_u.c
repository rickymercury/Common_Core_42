/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:07:11 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 20:29:21 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t u_digits(unsigned int n)
{
    size_t digits;

	digits = 0;
    if (n == 0)
        return (1);
    while (n != 0)
    {
        n /= 10;
        digits++;
    }
    return (digits);
}

char *ft_utoa(unsigned int n)
{
    char *str;
    int num_len;

    num_len = u_digits(n);
    str = (char *)malloc((num_len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    str[num_len] = '\0';
    while (num_len > 0)
    {
        str[num_len - 1] = (n % 10) + '0';
        n = n / 10;
        num_len--;
    }
    return (str);
}

int ft_print_u(unsigned int n)
{
    int num_len;
    char *str;

    if (n == 0)
        return write(1, "0", 1);
    str = ft_utoa(n);
    if (!str)
        return (-1);
    num_len = 0;
    while (str[num_len] != '\0')
        num_len++;
    write(1, str, num_len);
    free(str);
    return (num_len);
}