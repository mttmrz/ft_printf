/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_simple_printer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:39:33 by mmarzano          #+#    #+#             */
/*   Updated: 2022/11/10 19:39:36 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unb(unsigned int unb)
{
	if (unb > 9)
	{
		ft_putnbr_unb(unb / 10);
		ft_putnbr_unb(unb % 10);
	}
	else
		ft_putchar_sp(unb + 48);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar_sp('2');
		nb = 147483648;
	}
	if (nb < 0)
		nb *= -1;
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar_sp(nb + 48);
}

void	ft_puthex_ptr(uintptr_t p)
{
	uintptr_t	basel;

	basel = ft_strlen("0123456789abcdef");
	if (p < basel)
		ft_putchar_sp("0123456789abcdef"[p]);
	else
	{
		ft_puthex_ptr(p / basel);
		ft_puthex_ptr(p % basel);
	}
}

void	ft_puthex(unsigned int hex, int ver)
{
	unsigned int	basel;

	basel = ft_strlen("0123456789abcdef");
	if (hex < basel)
	{
		if (ver == 1 && ("0123456789abcdef"[hex] >= 'a'
				&& "0123456789abcdef"[hex] <= 'z'))
			ft_putchar_sp("0123456789abcdef"[hex] - 32);
		else
			ft_putchar_sp("0123456789abcdef"[hex]);
	}
	if (hex >= basel)
	{
		ft_puthex(hex / basel, ver);
		ft_puthex(hex % basel, ver);
	}
}
