/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:16:49 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/13 01:56:03 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(const char *str)
{
	int		i;
	int		count;
	const char	*null_str;

	count = 0;
	if (!str)
	{
		null_str = "(null)";
		while (*null_str)
		{
			count += ft_print_c(*null_str);
			null_str++;
		}
		return (count);
	}
	i = 0;
	while (str[i])
	{
		count += ft_print_c(str[i]);
		i++;
	}
	return (count);
}