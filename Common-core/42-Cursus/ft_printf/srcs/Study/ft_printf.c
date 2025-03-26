/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:05:59 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/26 09:04:41 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_p(const char *specifier, size_t len, va_list args)
{
	if (*specifier == 'p')
		len += ft_hexapointer(va_arg(args, unsigned long int));
	return (len);
}

int	ft_handle_x(const char *specifier, size_t len, va_list args)
{
	char	*string;

	string = NULL;
	if (*specifier == 'x')
	{
		string = ft_lowerhexa(va_arg(args, unsigned int));
		if (string == NULL)
			return (0);
		len += ft_strlen(string);
		ft_putstr_fd(string, 1);
		free (string);
	}
	else if (*specifier == 'X')
	{
		string = ft_upperhexa(va_arg(args, unsigned int));
		if (string == NULL)
			return (0);
		len += ft_strlen(string);
		ft_putstr_fd(string, 1);
		free (string);
	}
	else
		len = ft_handle_p(specifier, len, args);
	return (len);
} 

static int	ft_handle_diu(const char *specifier, size_t len, va_list args)
{
	char	*string;

	string = NULL;
	if (*specifier == 'd' || *specifier == 'i')
	{
		string = ft_itoa(va_arg(args, int));
		if (string == NULL)
			return (0);
		len += ft_strlen(string);
		ft_putstr_fd(string, 1);
		free (string);
	}
	else if (*specifier == 'u')
	{
		string = ft_itoa_u(va_arg(args, unsigned int));
		if (string == NULL)
			return (0);
		len += ft_strlen(string);
		ft_putstr_fd(string, 1);
		free (string);
	}
	else
		len = ft_handle_x(specifier, len, args);
	return (len);
}

static int	ft_handle_s(size_t len, va_list args)
{
	char	*string;
	string = NULL;
	string = ft_strdup(va_arg(args, char *));
	if (string == NULL)
	{
		write(1, "(null)", 6);
		len += 6;
		return (len);
	}
	len += ft_strlen(string);
	ft_putstr_fd(string, 1);
	free (string);
	return (len);
}

static int	ft_handle_c(const char *specifier, size_t len, va_list args)
{
	if (*specifier == '%')
	{
		len++;
		ft_putchar_fd(*specifier, 1);
	}
	else if (*specifier == 'c')
	{
		len++;
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if (*specifier == 's')
	{
		len = ft_handle_s(len, args);
	}
	else
		len = ft_handle_diu(specifier, len, args);
	return (len);
}

int	handle_format(va_list args, const char *str, size_t *i)
{
	int	len;

	len = 0;
	if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p' ||
		str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'u' ||
		str[*i] == 'x' || str[*i] == 'X' || str[*i] == '%')
	{
		len = ft_handle_c(&str[*i], len, args);
	}
	else
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(str[*i], 1);
		len = 2;
	}
	(*i)++;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	if (!format || (*format == '%' && format[1] == '\0'))
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
			ft_putchar_fd(format[i], 1);
			len++;
			i++;
		}
	}
	va_end(args);
	return (len);
}