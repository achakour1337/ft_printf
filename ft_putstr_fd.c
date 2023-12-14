/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:29:54 by achakour          #+#    #+#             */
/*   Updated: 2023/12/02 17:31:42 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(const char *s, int *len)
{
	size_t	i;

	if (!s)
	{
		ft_putstr_fd("(null)", len);
		return ;
	}
	i = -1;
	while (s[++i])
		*len += write(1, &s[i], 1);
}
