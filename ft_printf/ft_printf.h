/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:48:57 by hsuner            #+#    #+#             */
/*   Updated: 2023/10/27 15:31:18 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BASE10
#  define BASE10 "0123456789"
# endif

# ifndef BASE16LOWER
#  define BASE16LOWER "0123456789abcdef"
# endif

# ifndef BASE16UPPER
#  define BASE16UPPER "0123456789ABCDEF"
# endif

# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	type_convert(va_list va, char type);
int	ft_putchar(char c);

int	ft_strlen(char *base);
int	ft_putstr(char *str);
int	ft_putnbr(long n);
int	ft_putptr(unsigned long n, char *bs);
int	ft_unsnd_putnbr_base(unsigned int n, char *bs);

#endif