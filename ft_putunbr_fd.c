/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:16:52 by achakour          #+#    #+#             */
/*   Updated: 2023/12/02 17:31:46 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_fd(unsigned int n, int *len)
{
	if (n > 9)
	{
		ft_putunbr_fd(n / 10, len);
		*len += ft_putchar_fd((n % 10 + '0'), 1);
	}
	if (n <= 9)
		*len += ft_putchar_fd((n % 10 + '0'), 1);
}
