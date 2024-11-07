/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:07:11 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/07 14:59:57 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_length_num(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	int		index;
	char	*num;

	if (n == 0)
		return (write(1, "0", 1));
	
	len = ft_length_num(n);
	index = len;
	num = (char *)malloc((len + 1) * sizeof(char));
	if (!num)
		return (-1);
	
	num[index] = '\0';
	while (n != 0)
	{
		num[index - 1] = (n % 10) + '0';
		n /= 10;
		index--;
	}
	write(1, num, len);
	free(num);

	return (len);
}

/*
int	ft_length_num(unsigned int num)
{
	int	len = 0;

	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_length_num(n);
	num = (char *)malloc((len + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (len > 0)
	{
		num[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_putunsigned(unsigned int n)
{
	int		len;
	char	*num;

	if (n == 0)
		return (write(1, "0", 1));
	num = ft_utoa(n);
	if (!num)
		return (-1);
	len = 0;
	while (num[len] != '\0')
		len++;
	write(1, num, len);
	free(num);
	return (len);
}
*/

/*
#include <stdio.h>

int main(void)
{
    unsigned int num1 = 0;
    unsigned int num2 = 1234;
    unsigned int num3 = 4294967295;
    unsigned int num4 = 100000;

    printf("Output para num1 (0): ");
    fflush(stdout);
    ft_putunsigned(num1);
    printf("\n");

    printf("Output para num2 (1234): ");
    fflush(stdout);
    ft_putunsigned(num2);
    printf("\n");

    printf("Output para num3 (4294967295): ");
    fflush(stdout);
    ft_putunsigned(num3);
    printf("\n");

    printf("Output para num4 (100000): ");
    fflush(stdout);
    ft_putunsigned(num4);
    printf("\n");

    return 0;
}
*/

/**
 * Calculates the number of digits in an unsigned integer.
 *
 * The param n is the unsigned integer to analyze.
 *
 * This function determines how many digits are required to represent
 * the given unsigned integer 'n' in decimal notation. It repeatedly
 * divides 'n' by 10 until the value is reduced to 0, counting the number
 * of divisions.
 *
 * return the number of digits in the unsigned integer 'n'.
 */

/**
 * Prints an unsigned integer to the standard output (stdout).
 *
 * The param n is the unsigned integer to be printed.
 *
 * This function prints an unsigned integer 'n' by first calculating its length
 * in decimal digits using `ft_length_num`. It then allocates memory for a character
 * array to store the digits, converts the number to a string, and prints it.
 * If the value of 'n' is 0, it directly prints '0'. After printing, the allocated
 * memory is freed.
 *
 * return the number of characters printed.
 */