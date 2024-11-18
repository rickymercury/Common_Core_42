/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:09:28 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/18 23:25:19 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(t_flags *flags, const char *type, int *i, va_list args)
{
	int	count;
    char *s;

	count = 0;
	if (type[*i] == 'c')
		count += ft_print_c(flags, va_arg(args, int));
	if (type[*i] == 's')
    {
        s = va_arg(args, char*);
        if (s == NULL)
            s = "(null)";
        count += ft_print_s(flags, s);
    }
	if (type[*i] == 'p')
		count += ft_print_p(flags, va_arg(args, size_t));
	if (type[*i] == 'd' || type[*i] == 'i')
		count += ft_print_d(flags, va_arg(args, int));
	if (type[*i] == 'u')
		count += ft_print_d(flags, va_arg(args, unsigned int));
	if (type[*i] == 'x' || type[*i] == 'X')
		count += ft_print_x(flags, va_arg(args, unsigned int), type[*i]);
	if (type[*i] == '%')
		count += ft_putchar('%');
	(*i)++;
	return (count);
}

void	parse_flags(t_flags *flags, const char *flag, int *i)
{
	while (flag[*i] == '-' || flag[*i] == '+'
		|| flag[*i] == ' ' || flag[*i] == '#')
	{
		if (flag[*i] == '-')
			flags -> align_left = TRUE;
		if (flag[*i] == '+')
			flags -> plus = TRUE;
		if (flag[*i] == ' ')
			flags -> space = TRUE;
		if (flag[*i] == '#')
			flags -> hash = TRUE;
		(*i)++;
	}
	if (flag[*i] == '0')
		flags -> zero = TRUE;
	if (ft_isdigit(flag[*i]) || flag[*i] == '.')
	{
		if (flag[*i] == '.')
			flags -> precision = ft_atoi(&flag[++*i]) + 1;
		else
			flags -> width = ft_atoi(&flag[*i]);
		while (ft_isdigit(flag[*i]))
			(*i)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;
	int		i;
	int		count;

	if (!str || (str[0] == '%' && str[1] == '\0'))
		return (-1);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		ft_bzero(&flags, sizeof(t_flags));
		if (str[i] == '%')
		{
			i++;
			while (ft_memchr("-0.# +", str[i], 6) || ft_isdigit(str[i]))
				parse_flags(&flags, str, &i);
			count += print_format(&flags, str, &i, args);
		}
		else
			count += ft_putchar(str[i++]);
	}
	va_end(args);
	return (count);
}