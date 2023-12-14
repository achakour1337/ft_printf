/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:36:03 by achakour          #+#    #+#             */
/*   Updated: 2023/12/07 18:07:28 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int *len)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		*len += ft_putchar_fd('-', 1);
		nbr = -n;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, len);
		*len += ft_putchar_fd((nbr % 10 + '0'), 1);
	}
	if (nbr <= 9)
		*len += ft_putchar_fd((nbr % 10 + '0'), 1);
}
