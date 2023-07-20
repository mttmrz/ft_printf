/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flg_printer_core2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:39:50 by mmarzano          #+#    #+#             */
/*   Updated: 2022/11/10 19:39:57 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_flg_minus(int nb, char *flg, int slen, int sign)
{
	int	len;

	len = 0;
	if (nb >= 0)
		len += ft_putflg_start(flg, 'd');
	else
		ft_putchar_sp('-');
	len += ft_putflg_zero(flg, slen, sign);
	if (!(ft_scnd_pdng(flg) == 0 && nb == 0))
		ft_putnbr(nb);
	len += ft_putflg_spc(flg, slen, 'd', sign);
	return (len);
}

int	ft_putnbr_flg_std(int nb, char *flg, int slen, int sign)
{
	int	len;

	len = 0;
	len += ft_putflg_spc(flg, slen, 'd', sign);
	if (nb >= 0)
		len += ft_putflg_start(flg, 'd');
	else
		ft_putchar_sp('-');
	len += ft_putflg_zero(flg, slen, sign);
	if (!(ft_scnd_pdng(flg) == 0 && nb == 0))
		ft_putnbr(nb);
	return (len);
}

int	ft_putnbr_unb_flg_minus(unsigned int unb, char *flg, int slen)
{
	int	len;

	len = 0;
	len += ft_putflg_start(flg, 'u');
	len += ft_putflg_zero(flg, slen, 0);
	if (!(ft_scnd_pdng(flg) == 0 && unb == 0))
		ft_putnbr_unb(unb);
	len += ft_putflg_spc(flg, slen, 'u', 0);
	return (len);
}

int	ft_putnbr_unb_flg_std(unsigned int unb, char *flg, int slen)
{
	int	len;

	len = 0;
	len += ft_putflg_spc(flg, slen, 'u', 0);
	len += ft_putflg_start(flg, 'u');
	len += ft_putflg_zero(flg, slen, 0);
	if (!(ft_scnd_pdng(flg) == 0 && unb == 0))
		ft_putnbr_unb(unb);
	return (len);
}
