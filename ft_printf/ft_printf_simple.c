/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:40:14 by mmarzano          #+#    #+#             */
/*   Updated: 2022/11/10 19:40:17 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_chars(char c, va_list ap)
{
	int		len;
	char	*str;
	char	ch;

	len = 0;
	if (c == 's')
	{
		str = va_arg(ap, char *);
		if (str == NULL)
		{
			len += ft_putstr_sp_flg("(null)", 6);
			return (len);
		}
		while (str[len] != '\0')
			len += ft_putchar_sp(str[len]);
	}
	else if (c == '%')
		len += ft_putchar_sp('%');
	else
	{
		ch = va_arg(ap, int);
		len += ft_putchar_sp(ch);
	}
	return (len);
}

int	ft_print_num(char c, va_list ap)
{
	int				len;
	int				nb;
	unsigned int	unb;

	len = 0;
	if (c == 'u')
	{
		unb = va_arg(ap, unsigned int);
		len += ft_uintlen(unb);
		ft_putnbr_unb(unb);
	}
	else
	{
		nb = va_arg(ap, int);
		len += ft_intlen(nb);
		if (nb < 0)
			ft_putchar_sp('-');
		ft_putnbr(nb);
	}
	return (len);
}

int	ft_print_hex(char c, va_list ap)
{
	int				len;
	uintptr_t		p;
	unsigned int	hex;

	len = 0;
	if (c == 'p')
	{
		p = va_arg(ap, uintptr_t);
		len += ft_putptr_core(p);
	}
	else
	{
		hex = va_arg(ap, int);
		len += ft_hexlen(hex);
		if (c == 'X')
			ft_puthex(hex, 1);
		else
			ft_puthex(hex, 0);
	}
	return (len);
}

int	ft_putptr_core(uintptr_t p)
{
	int	len;

	len = 0;
	if (p == 0)
	{
		len += ft_putstr_sp_flg("(nil)", 5);
		return (len);
	}
	len += ft_putstr_sp_flg("0x", 2);
	len += ft_ptrlen(p);
	ft_puthex_ptr(p);
	return (len);
}
