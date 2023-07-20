/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:39:08 by mmarzano          #+#    #+#             */
/*   Updated: 2022/11/10 19:39:11 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uintlen(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int	ft_ptrlen(uintptr_t nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

int	ft_flgspc_utilszero(int frst_pdng, int scnd_pdng, int sign)
{
	int	len;

	len = 0;
	if (sign == 1)
		len += ft_putpadding(frst_pdng - scnd_pdng - 1, ' ');
	else
		len += ft_putpadding(frst_pdng - scnd_pdng - len, ' ');
	return (len);
}

int	ft_flgspc_utils(int frst_pdng, int scnd_pdng, int sign)
{
	int	len;

	len = 0;
	if (sign == 1)
		len += ft_putpadding(frst_pdng - scnd_pdng - 1, ' ');
	else
		len += ft_putpadding(frst_pdng - scnd_pdng, ' ');
	return (len);
}

void	ft_flgspc_utils_prep(char c, char *flg, int slen)
{
	int	scnd_pdng;

	scnd_pdng = ft_scnd_pdng(flg);
	if (ft_putflg_checklen(flg, c) != 0 && scnd_pdng != 0 && scnd_pdng > slen)
		scnd_pdng += ft_putflg_checklen(flg, c);
	else if (ft_putflg_checklen(flg, c) != 0)
		slen += ft_putflg_checklen(flg, c);
}
