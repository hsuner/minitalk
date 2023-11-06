/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_utilities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:53:34 by hsuner            #+#    #+#             */
/*   Updated: 2023/10/27 15:31:46 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int	ft_putptr(unsigned long n, char *bs)
{
	int				printed;
	unsigned int	baseln;

	printed = 0;
	baseln = (unsigned int)ft_strlen(bs);
	if (n >= baseln)
	{
		printed += ft_putptr(n / baseln, bs);
		printed += ft_putptr(n % baseln, bs);
	}
	else
		printed += ft_putchar(bs[n % baseln]);
	return (printed);
}

int	ft_putnbr(long n)
{
	int	len;
	int	tmp;

	len = 0;
	if (n < 0)
	{
		tmp = write(1, "-", 1);
		if (tmp == -1)
			return (-1);
		len++;
		n = -n;
	}
	if (n >= 10)
	{
		tmp = ft_putnbr(n / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789"[n % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_unsnd_putnbr_base(unsigned int n, char *bs)
{
	int				count;
	int				tmp;
	unsigned int	base_len;

	count = 0;
	base_len = ft_strlen(bs);
	if (n >= (unsigned int)base_len)
	{
		tmp = ft_unsnd_putnbr_base(n / base_len, bs);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (ft_putchar(bs[n % base_len]) == -1)
		return (-1);
	return (++count);
}
