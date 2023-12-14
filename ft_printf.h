/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:26:53 by achakour          #+#    #+#             */
/*   Updated: 2023/12/09 14:38:08 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void             print_hex_up(long n, int *len);
void             print_hex_down(unsigned long n, short int flag, int *len);
int	             ft_putchar_fd(char c, int fd);
void	         ft_putnbr_fd(int n, int *len);
void	         ft_putstr_fd(const char *s, int *len);
int              ft_printf(const char *format, ...);
void	         ft_putunbr_fd(unsigned int n, int *len);

#endif