/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:53:13 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/08 16:10:56 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(int n)
{
	int	count;

    count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char *ft_itoa(int n)
{
	int		size;
	char	*str;
	long	nbr;

	nbr = n;
	size = ft_count_digits(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[size--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

int	ft_print_d(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_print_s("-2147483648\n"));

	str = ft_itoa(n);
	if (!str)
		return (0);

	len = ft_print_s(str);
	len += ft_print_s("\n");
	free(str);
	return (len);
}

#include <stdio.h>

int	main(void)
{
	int	len;

	len = ft_print_d(123);

	len = ft_print_d(-456);

	len = ft_print_d(0);

	len = ft_print_d(-2147483648);

	len = ft_print_d(789);

	len = ft_print_d(-987);

	return (0);
}

/*
1. Overview of the Process

The purpose of the ft_itoa function is to convert an integer (both positive and negative) into its string representation. The goal of ft_print_number is to format this number for output, specifically for printing it as a string, and handle special cases such as the minimum integer value and zero. Here's a breakdown of how both functions work together to achieve this.
2. Handling Special Cases
MIN_VALUE of int

In C, the integer data type has a defined minimum and maximum value. The smallest possible value for a signed 32-bit integer is -2147483648 (represented by INT_MIN in some cases). This value is problematic because its absolute value (2147483648) exceeds the maximum positive value that can be represented by an int type in C, which is 2147483647.

Therefore, the first thing we need to do is check for this edge case specifically, as this number cannot be converted normally (since its absolute value is out of bounds). If the input number is -2147483648, we handle it as a special case by directly returning the string "-2147483648". This avoids issues with converting the number using the standard method (which would overflow).
Zero (0)

The number 0 is another special case that needs explicit handling. Since ft_itoa would generate an empty string for 0 if not treated properly, we explicitly check for this case before proceeding to conversion. If n == 0, we immediately set the string representation to "0".
3. Handling Negative Numbers

If the number is negative, we need to convert it to its positive counterpart for easier processing. This is done in the following steps:

    Write the - sign: Since we know the number is negative, the first step is to print the minus sign ('-') before the rest of the digits.

    Convert the number to positive: To make the process of conversion easier, we multiply the number by -1 (i.e., convert it to positive). This step is essential because the conversion logic relies on working with positive numbers.

4. Conversion Logic with ft_itoa

Once the number is either positive or adjusted for a negative value, we proceed to convert the number into a string. This process is done using the following steps:
Counting the Number of Digits

    We begin by determining how many digits the number has. This is crucial because we need to allocate memory for the string, and we need to know how much space to reserve.
    We use the ft_digit_count function (formerly ft_numlen) to count the number of digits in the number. This function works by repeatedly dividing the number by 10, which reduces it one digit at a time, while also increasing a counter (len) to keep track of the total number of digits.

Memory Allocation

    After determining how many digits the number has, we allocate memory for the string (num_rep). The string will need enough space to store each digit of the number plus one extra byte for the null-terminator ('\0'), which marks the end of the string.

    If the number is negative, we also reserve space for the minus sign ('-').

Populating the String

    Using the modulus operator (% 10), we extract the rightmost digit of the number. This is done repeatedly to get each digit from right to left.

        For example, if the number is 12345, the first digit we get using nbr % 10 will be 5, and we store this in the string.

        After extracting the digit, we reduce the number by dividing it by 10 (nbr /= 10), which effectively "removes" the last digit.

    This process continues until there are no more digits to extract (i.e., the number becomes 0).

Storing Digits in the Correct Order

    Since we are extracting digits from right to left (starting with the least significant digit), the digits are stored in the string in reverse order.

    Once all the digits are stored, we reverse the string by starting at the end and writing the digits from right to left (from the position determined by digit_pos).

5. Printing the Number

Once the number has been converted into a string (num_rep), we need to print it out. This is done using ft_print_s, a function that prints strings one character at a time.

    Reversing the Digits: Before printing, the digits are in reverse order. So, when printing the digits, we print them one by one, starting from the last digit (using a loop that starts at the end of the string and moves backwards).

    Appending a Newline: After printing the number, we add a newline character to ensure that the next output starts on a new line. This is handled by adding "\n" to the final output string.

    Freeing Memory: Once the number has been printed, we free the memory allocated for the string to avoid memory leaks.

6. Complete Process Summary

    First, check if the number is -2147483648 (special case) or 0 (special case) and handle them directly.
    If the number is negative, print the minus sign and convert the number to positive.
    Count the digits of the number, allocate memory for the resulting string, and use modulus and division to extract and store the digits.
    Print the string representation of the number, ensuring the digits are printed in the correct order.
    Add a newline and free the memory allocated for the string.
*/


/*
#include "ft_printf.h"

int	ft_printf_nbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (nb < 0)
	{
		len += write(1, "-", 1);
		nb = -nb;
		len += ft_printf_nbr(nb);
	}
	else if (nb > 9)
	{
		len += ft_printf_nbr(nb / 10);
		len += ft_printf_nbr(nb % 10);
	}
	else
	{
		nb += 48;
		len += write(1, &nb, 1);
	}
	return (len);
}
*/