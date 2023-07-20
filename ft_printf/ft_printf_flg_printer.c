/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flg_printer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:38:09 by mmarzano          #+#    #+#             */
/*   Updated: 2022/11/10 19:38:11 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unb_flg(unsigned int unb, char *flg)
{
	int	len;
	int	slen;

	slen = ft_uintlen(unb);
	len = slen;
	if (ft_scnd_pdng(flg) == 0 && unb == 0)
	{
		slen--;
		len--;
	}
	if (ft_isinflag(flg, '-') == 1)
		len += ft_putnbr_unb_flg_minus(unb, flg, slen);
	else
		len += ft_putnbr_unb_flg_std(unb, flg, slen);
	return (len);
}

int	ft_putnbr_flg(int nb, char *flg)
{
	int	len;
	int	slen;
	int	sign;

	sign = 0;
	slen = ft_intlen(nb);
	if (ft_scnd_pdng(flg) == 0 && nb == 0)
		slen--;
	len = slen;
	if (nb < 0)
		sign = 1;
	if (ft_isinflag(flg, '-') == 1)
		len += ft_putnbr_flg_minus(nb, flg, slen, sign);
	else
		len += ft_putnbr_flg_std(nb, flg, slen, sign);
	return (len);
}

int	ft_puthex_ptr_flg(uintptr_t p, char *flg)
{
	int	len;
	int	slen;

	if (p == 0)
	{
		slen = 5;
		len = 0;
	}
	else
	{
		slen = ft_ptrlen(p) + 2;
		len = ft_ptrlen(p);
	}
	if (ft_isinflag(flg, '-') == 1)
		len += ft_puthex_ptr_flg_minus(p, flg, slen);
	else
		len += ft_puthex_ptr_flg_std(p, flg, slen);
	return (len);
}

int	ft_puthex_flg(int hex, int ver, char *flg)
{
	int	len;
	int	slen;

	slen = ft_hexlen(hex);
	len = slen;
	if (hex == 0 && ft_scnd_pdng(flg) == 0)
	{
		slen = 0;
		len = 0;
	}
	if (ft_isinflag(flg, '-') == 1)
		len += ft_puthex_flg_minus(hex, ver, flg, slen);
	else
		len += ft_puthex_flg_std(hex, ver, flg, slen);
	return (len);
}
