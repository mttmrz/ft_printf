/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:36:40 by mmarzano          #+#    #+#             */
/*   Updated: 2022/11/10 19:36:45 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_sp(char c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_takeflag(char *s, int i)
{
	char	*flg;
	int		len;
	int		j;

	j = 0;
	len = 0;
	i++;
	while (ft_isspec(s[i + len], "udixXpsc%") != 1)
		len++;
	if (len == 0)
		return (NULL);
	flg = (char *)malloc(sizeof(char) * (len + 1));
	while (j < len)
	{
		flg[j] = s[i + j];
		j++;
	}
	flg[j] = '\0';
	return (flg);
}

int	ft_print(char c, va_list ap, char *flg)
{
	int	len;

	len = 0;
	if (flg[0] == '\0')
		len += ft_print_simple(c, ap);
	else
		len += ft_print_flg(c, ap, flg);
	return (len);
}

int	ft_printf_main(const char *s, va_list ap)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			str = ft_takeflag((char *)s, i);
			if (!(str))
				len += ft_print(s[++i], ap, "");
			else
			{
				i += ft_strlen(str) + 1;
				len += ft_print(s[i], ap, str);
			}
			free(str);
		}
		else
			len += ft_putchar_sp(s[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, s);
	len = ft_printf_main(s, ap);
	va_end(ap);
	return (len);
}
