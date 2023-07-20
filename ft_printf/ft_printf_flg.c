/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:37:32 by mmarzano          #+#    #+#             */
/*   Updated: 2022/11/10 19:37:35 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_chars_flg(char c, va_list ap, char *flg)
{
	int		len;
	char	*str;
	char	ch;

	len = 0;
	if (c == 's')
	{
		str = va_arg(ap, char *);
		len += ft_putstr_flg(str, flg);
	}
	else if (c == '%')
		len += ft_putchar_sp_flg('%', flg);
	else
	{
		ch = va_arg(ap, int);
		len += ft_putchar_sp_flg(ch, flg);
	}
	return (len);
}

int	ft_print_num_flg(char c, va_list ap, char *flg)
{
	int				len;
	int				nb;
	unsigned int	unb;

	len = 0;
	if (c == 'u')
	{
		unb = va_arg(ap, unsigned int);
		len += ft_putnbr_unb_flg(unb, flg);
	}
	else
	{
		nb = va_arg(ap, int);
		len += ft_putnbr_flg(nb, flg);
	}
	return (len);
}

int	ft_print_hex_flg(char c, va_list ap, char *flg)
{
	int			len;
	uintptr_t	p;
	int			hex;

	len = 0;
	if (c == 'p')
	{
		p = va_arg(ap, uintptr_t);
		len += ft_puthex_ptr_flg(p, flg);
	}
	else
	{
		hex = va_arg(ap, int);
		if (c == 'X')
			len += ft_puthex_flg(hex, 1, flg);
		else
			len += ft_puthex_flg(hex, 0, flg);
	}
	return (len);
}
