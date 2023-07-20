/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flg_printer2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:38:23 by mmarzano          #+#    #+#             */
/*   Updated: 2022/11/10 19:38:25 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_flg(char *str, char *flg)
{
	int	len;
	int	slen;

	len = 0;
	if (ft_scnd_pdng(flg) != -1)
		slen = ft_scnd_pdng(flg);
	else
	{
		if (str == NULL)
			slen = 6;
		else
			slen = ft_strlen(str);
	}
	if (ft_isinflag(flg, '-') == 1)
		len += ft_putstr_flg_minus(str, flg, slen);
	else
		len += ft_putstr_flg_std(str, flg, slen);
	return (len);
}

int	ft_putchar_sp_flg(char ch, char *flg)
{
	int	len;

	len = 0;
	if (ft_isinflag(flg, '-') == 1)
	{
		len += ft_putflg_start(flg, 'c');
		len += ft_putchar_sp(ch);
		len += ft_putflgchars_aft(flg, 1, 1);
	}
	else
	{
		len += ft_putflg_start(flg, 'c');
		len += ft_putflgchars_aft(flg, 1, 1);
		len += ft_putchar_sp(ch);
	}
	return (len);
}

int	ft_putstr_flg_minus(char *str, char *flg, int slen)
{
	int	len;

	len = 0;
	len += ft_putflg_start(flg, 's');
	if (str == NULL && ft_scnd_pdng(flg) == -1)
		len += ft_putstr_sp_flg("(null)", 6);
	else if (str == NULL && ft_scnd_pdng(flg) != -1)
	{
		if (ft_scnd_pdng(flg) >= 6)
			len += ft_putstr_sp_flg("(null)", 6);
		else
			len += ft_putstr_sp_flg("", 0);
	}
	else
		len += ft_putstr_sp_flg(str, slen);
	len += ft_putflgchars_aft(flg, slen, ft_strlen(str));
	return (len);
}

int	ft_putstr_flg_std(char *str, char *flg, int slen)
{
	int	len;

	len = 0;
	len += ft_putflg_start(flg, 's');
	len += ft_putflgchars_aft(flg, slen, ft_strlen(str));
	if (str == NULL && ft_scnd_pdng(flg) == -1)
		len += ft_putstr_sp_flg("(null)", 6);
	else if (str == NULL && ft_scnd_pdng(flg) != -1)
	{
		if (ft_scnd_pdng(flg) >= 6)
			len += ft_putstr_sp_flg("(null)", 6);
		else
			len += ft_putstr_sp_flg("", 0);
	}
	else
		len += ft_putstr_sp_flg(str, slen);
	return (len);
}
