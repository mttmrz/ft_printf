/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:39:25 by mmarzano          #+#    #+#             */
/*   Updated: 2022/11/10 19:39:27 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_sp_flg(char *str, int slen)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (slen == 0)
		return (0);
	while (i < slen && str[i] != '\0')
	{
		len += ft_putchar_sp(str[i]);
		i++;
	}
	return (len);
}

int	ft_putpadding(int len, char c)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_sp(c);
		i++;
	}
	return (len);
}

int	ft_isspec(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_intlen(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int	ft_hexlen(unsigned int hex)
{
	int	i;

	i = 0;
	if (hex == 0)
		return (1);
	while (hex > 0)
	{
		i++;
		hex = hex / 16;
	}
	return (i);
}
