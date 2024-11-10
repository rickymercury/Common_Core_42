/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:16:49 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/07 19:18:43 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *str)
{
	int		i;
	int		count;
	int		write_result;

	i = 0;
	count = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		write_result = write(1, &str[i], 1);
		if (write_result == -1)
			return (-1);
		count++;
		i++;
	}
	return (count);
}