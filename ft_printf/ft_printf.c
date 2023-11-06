/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:08:28 by hsuner            #+#    #+#             */
/*   Updated: 2023/10/27 15:31:36 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		total_byte;
	int		tmp;

	va_start(args, str);
	i = -1;
	total_byte = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			tmp = type_convert(args, str[++i]);
			if (tmp == -1)
				return (-1);
			total_byte += tmp - 1;
		}
		else if (write(1, &str[i], 1) == -1)
			return (-1);
		total_byte++;
	}
	va_end(args);
	return (total_byte);
}

int	type_convert(va_list va, char type)
{
	int	tmp;

	if (type == 'c')
		return (ft_putchar(va_arg(va, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(va, char *)));
	else if (type == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		tmp = ft_putptr(va_arg(va, unsigned long), BASE16LOWER);
		return (tmp + 2);
	}
	else if (type == 'i' || type == 'd')
		return (ft_putnbr(va_arg(va, int)));
	else if (type == 'u')
		return (ft_unsnd_putnbr_base(va_arg(va, unsigned int), BASE10));
	else if (type == 'x')
		return (ft_unsnd_putnbr_base(va_arg(va, unsigned int), BASE16LOWER));
	else if (type == 'X')
		return (ft_unsnd_putnbr_base(va_arg(va, unsigned int), BASE16UPPER));
	else if (type == '%')
		return (ft_putchar('%'));
	return (0);
}
