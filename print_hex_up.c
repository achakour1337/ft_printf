/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:01:21 by achakour          #+#    #+#             */
/*   Updated: 2023/12/09 14:40:50 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_hex_up(long n, int *len)
{
    char    *format;

    format = "0123456789ABCDEF";
    if (n >= 16)
    {
        print_hex_up(n >> 4, len);
        *len += ft_putchar_fd(format[n & 0xf], 1);
    }
    if (n < 16)
        *len += ft_putchar_fd(format[n & 0xf], 1);
}
