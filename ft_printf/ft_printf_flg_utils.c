/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flg_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:40:23 by mmarzano          #+#    #+#             */
/*   Updated: 2022/11/10 19:40:25 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_frst_pdng(char *flg)
{
	int	i;

	i = 0;
	while (ft_isspec(flg[i], "-+0 #"))
		i++;
	while (flg[i] != '.' && flg[i] != '\0')
	{
		if (ft_isdigit(flg[i]) != 0)
			return (ft_atoi(flg + i));
		i++;
	}
	return (0);
}

int	ft_scnd_pdng(char *flg)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (flg[i] != '\0')
	{
		if (ft_isdigit(flg[i]) != 0 && c == 1)
			return (ft_atoi(flg + i));
		if (flg[i] == '.')
			c++;
		i++;
	}
	if (c != 0)
		return (0);
	else
		return (-1);
}

int	ft_isinflag(char *flg, char c)
{
	int	i;

	i = 0;
	while (!(flg[i] >= '1' && flg[i] <= '9') && flg[i])
	{
		if (flg[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_plusandspacecheck(char *flg)
{
	int	cp;
	int	cs;

	cp = ft_isinflag(flg, '+');
	cs = ft_isinflag(flg, ' ');
	if (cs + cp >= 1)
	{
		if (cp == 0)
			return (1);
		else
			return (2);
	}
	else
		return (0);
}
