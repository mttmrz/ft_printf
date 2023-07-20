/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:37:16 by mmarzano          #+#    #+#             */
/*   Updated: 2022/11/10 19:37:19 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_simple(char c, va_list ap)
{
	int	len;

	len = 0;
	if (c == 'c' || c == 's' || c == '%')
		len += ft_print_chars(c, ap);
	else if (c == 'i' || c == 'd' || c == 'u')
		len += ft_print_num(c, ap);
	else if (c == 'x' || c == 'X' || c == 'p')
		len += ft_print_hex(c, ap);
	return (len);
}

int	ft_print_flg(char c, va_list ap, char *flg)
{
	int	len;

	len = 0;
	if (c == 'c' || c == 's' || c == '%')
		len = ft_print_chars_flg(c, ap, flg);
	else if (c == 'i' || c == 'd' || c == 'u')
		len = ft_print_num_flg(c, ap, flg);
	else if (c == 'x' || c == 'X' || c == 'p')
		len = ft_print_hex_flg(c, ap, flg);
	return (len);
}
