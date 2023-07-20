/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flg_printer_core.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:38:41 by mmarzano          #+#    #+#             */
/*   Updated: 2022/11/10 19:38:44 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_ptr_flg_minus(uintptr_t p, char *flg, int slen)
{
	int	len;

	len = 0;
	len += ft_putflg_start(flg, 'p');
	if (p != 0)
		len += ft_putstr_sp_flg("0x", 2);
	len += ft_putflg_zero(flg, slen, 0);
	if (p == 0)
		len += ft_putstr_sp_flg("(nil)", 6);
	else
		ft_puthex_ptr(p);
	len += ft_putflg_spc(flg, slen, 'p', 0);
	return (len);
}

int	ft_puthex_ptr_flg_std(uintptr_t p, char *flg, int slen)
{
	int	len;

	len = 0;
	len += ft_putflg_spc(flg, slen, 'p', 0);
	len += ft_putflg_start(flg, 'p');
	if (p != 0)
		len += ft_putstr_sp_flg("0x", 2);
	len += ft_putflg_zero(flg, slen, 0);
	if (p == 0)
	{
		len += ft_putstr_sp_flg("(nil)", 6);
	}
	else
		ft_puthex_ptr(p);
	return (len);
}

int	ft_puthex_flg_std(int hex, int ver, char *flg, int slen)
{
	int	len;

	len = 0;
	len += ft_putflg_spc(flg, slen, 'x', 0);
	if (hex != 0)
	{
		if (ver == 1)
			len += ft_putflg_start(flg, 'X');
		else
			len += ft_putflg_start(flg, 'x');
	}
	len += ft_putflg_zero(flg, slen, 0);
	if (!(hex == 0 && ft_scnd_pdng(flg) == 0))
		ft_puthex(hex, ver);
	return (len);
}

int	ft_puthex_flg_minus(int hex, int ver, char *flg, int slen)
{
	int	len;

	len = 0;
	if (hex != 0)
	{
		if (ver == 1)
			len += ft_putflg_start(flg, 'X');
		else
			len += ft_putflg_start(flg, 'x');
	}
	len += ft_putflg_zero(flg, slen, 0);
	if (!(hex == 0 && ft_scnd_pdng(flg) == 0))
		ft_puthex(hex, ver);
	len += ft_putflg_spc(flg, slen, 'x', 0);
	return (len);
}
