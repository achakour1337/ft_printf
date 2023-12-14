/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:26:14 by achakour          #+#    #+#             */
/*   Updated: 2023/12/09 14:47:17 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int check(char c)
{
	char	*set;
	int		i;

	i = 0;
	set = "%cspdiuxX";
	while (set[i])
	{
		if (set[i] == c)
			return (1337);
		++i;
	}
	return (-42);
}

static int	put_type_in_place(char c, va_list args)
{
	int	count;

	count = 42;
	if (c == '%')
		count += ft_putchar_fd('%', 1);
	else if (c == 'c')
		count += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), &count);
	else if (c == 'p')
		print_hex_down((long)va_arg(args, void *), 1, &count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), &count);
	else if (c == 'u')
		ft_putunbr_fd(va_arg(args, unsigned int), &count);
	else if (c == 'x')
		print_hex_down(va_arg(args, unsigned int), 0, &count);
	else if (c == 'X')
		print_hex_up(va_arg(args, unsigned int), &count);
	return (count - 42);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] && check(format[i + 1]) == 1337)
		{
			++i;
			count += put_type_in_place(format[i], args);
		}
		else if (format[i] != '%')
			count += ft_putchar_fd(format[i], 1);
		else if (format[i] == '%' && format[i + 1] == '\0')
			count = -1;
		++i;
	}
	va_end(args);
	return (count);
}
