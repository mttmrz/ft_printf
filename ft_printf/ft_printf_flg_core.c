/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flg_core.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:37:54 by mmarzano          #+#    #+#             */
/*   Updated: 2022/11/10 19:37:56 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putflg_start(char *flg, char c)
{
	int	len;

	len = 0;
	if ((c == 'd' || c == 'i') && ft_plusandspacecheck(flg) == 0)
		return (0);
	if ((c == 'd' || c == 'i') && ft_plusandspacecheck(flg) == 1)
		len += ft_putchar_sp(' ');
	if ((c == 'd' || c == 'i') && ft_plusandspacecheck(flg) == 2)
		len += ft_putchar_sp('+');
	if (c == 'p' && ft_isinflag(flg, '+') == 1)
		len += ft_putchar_sp('+');
	if (c == 'X' && ft_isinflag(flg, '#') == 1)
		len += ft_putstr_sp_flg("0X", 2);
	if (c == 'x' && ft_isinflag(flg, '#') == 1)
		len += ft_putstr_sp_flg("0x", 2);
	if (len < 0)
		return (0);
	return (len);
}

int	ft_putflg_zero(char *flg, int slen, int sign)
{
	int	frst_pdng;
	int	scnd_pdng;
	int	len;

	len = 0;
	frst_pdng = ft_frst_pdng(flg);
	scnd_pdng = ft_scnd_pdng(flg);
	if (ft_isinflag(flg, '0') == 1 && frst_pdng != 0 && scnd_pdng == -1)
		len += ft_putpadding(frst_pdng - slen, '0');
	if (ft_isinflag(flg, '0') == 1 && frst_pdng != 0 && scnd_pdng > 0)
		len += ft_putpadding(scnd_pdng - (slen - sign), '0');
	if (ft_isinflag(flg, '0') == 1 && frst_pdng == 0 && scnd_pdng > 0)
		len += ft_putpadding(scnd_pdng - (slen - sign), '0');
	if (ft_isinflag(flg, '0') == 0 && scnd_pdng != 0)
		len += ft_putpadding(scnd_pdng - (slen - sign), '0');
	if (len < 0)
		return (0);
	return (len);
}

int	ft_putflg_spc(char *flg, int slen, char c, int sign)
{
	int	frst_pdng;
	int	scnd_pdng;
	int	len;

	len = 0;
	frst_pdng = ft_frst_pdng(flg);
	scnd_pdng = ft_scnd_pdng(flg);
	ft_flgspc_utils_prep(c, flg, slen);
	if (ft_isinflag(flg, '0') == 0 && frst_pdng != 0 && scnd_pdng == 0)
		len += ft_putpadding(frst_pdng - slen, ' ');
	else if (ft_isinflag(flg, '0') == 0 && frst_pdng != 0 && scnd_pdng != 0
		&& scnd_pdng >= slen)
		len += ft_flgspc_utilszero(frst_pdng, scnd_pdng, sign);
	else if (ft_isinflag(flg, '0') == 0)
		len += ft_putpadding(frst_pdng - slen, ' ');
	else if (ft_isinflag(flg, '0') == 1 && frst_pdng >= 0
		&& scnd_pdng >= 0 && scnd_pdng >= slen)
		len += ft_flgspc_utils(frst_pdng, scnd_pdng, sign);
	else if (ft_isinflag(flg, '0') == 1 && frst_pdng >= 0
		&& scnd_pdng >= 0 && scnd_pdng < slen)
		len += ft_putpadding(frst_pdng - slen, ' ');
	if (len < 0)
		return (0);
	return (len);
}

int	ft_putflgchars_aft(char *flg, int slen, int len)
{
	int	frst_pdng;
	int	scnd_pddng;
	int	splen;

	splen = 0;
	frst_pdng = ft_frst_pdng(flg);
	scnd_pddng = ft_scnd_pdng(flg);
	if (frst_pdng != 0)
	{
		if (len == 0 || (scnd_pddng != -1 && scnd_pddng < len))
			splen += ft_putpadding(frst_pdng - slen, ' ');
		else
			splen += ft_putpadding(frst_pdng - len, ' ');
	}
	if (splen <= 0)
		return (0);
	return (splen);
}

int	ft_putflg_checklen(char *flg, char c)
{
	int	len;

	len = 0;
	if ((c == 'd' || c == 'i') && ft_plusandspacecheck(flg) == 1)
		len += 1;
	if ((c == 'd' || c == 'i') && ft_plusandspacecheck(flg) == 2)
		len += 1;
	if (c == 'p' && ft_isinflag(flg, '+') == 1)
		len += 1;
	if (c == 'X' && ft_isinflag(flg, '#') == 1)
		len += 2;
	if (c == 'x' && ft_isinflag(flg, '#') == 1)
		len += 2;
	return (len);
}
