/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:03:43 by achakour          #+#    #+#             */
/*   Updated: 2023/12/09 14:41:09 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex_down(unsigned long n, short int flag, int *len)
{
    char	*format;

	format = "0123456789abcdef";
	if (!n && (flag & 1))
	{
		ft_putstr_fd("(nil)", len);
		return ;
	}
	if (flag & 1)
		ft_putstr_fd("0x", len);
    if (n >= 16)
    {
        print_hex_down(n >> 4, 0, len);
		*len += ft_putchar_fd(format[n & 0xf], 1);
    }
	if (n < 16)
		*len += ft_putchar_fd(format[n & 0xf], 1);
}
