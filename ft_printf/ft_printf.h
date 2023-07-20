/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:37:02 by mmarzano          #+#    #+#             */
/*   Updated: 2022/11/10 19:37:05 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdlib.h>
# include<stddef.h>
# include<stdint.h>
# include<stdarg.h>

int		ft_atoi(const char *nptr);
int		ft_isdigit(unsigned char c);
int		ft_intlen(int nb);
int		ft_hexlen(unsigned int hex);
int		ft_uintlen(unsigned int nb);
int		ft_ptrlen(uintptr_t nb);
int		ft_flgspc_utils(int frst_pdng, int scnd_pdng, int sign);
int		ft_flgspc_utilszero(int frst_pdng, int scnd_pdng, int sign);
int		ft_putptr_core(uintptr_t p);
int		ft_putnbr_unb_flg_minus(unsigned int unb, char *flg, int slen);
int		ft_putnbr_flg_std(int nb, char *flg, int slen, int sign);
int		ft_putnbr_flg_minus(int nb, char *flg, int slen, int sign);
int		ft_putnbr_unb_flg_std(unsigned int unb, char *flg, int slen);
int		ft_puthex_flg_minus(int hex, int ver, char *flg, int slen);
int		ft_puthex_flg_std(int hex, int ver, char *flg, int slen);
int		ft_puthex_ptr_flg_minus(uintptr_t p, char *flg, int slen);
int		ft_puthex_ptr_flg_std(uintptr_t p, char *flg, int slen);
int		ft_putstr_flg_minus(char *str, char *flg, int slen);
int		ft_putstr_flg_std(char *str, char *flg, int slen);
int		ft_printf(const char *s, ...);
int		ft_printf_main(const char *s, va_list ap);
int		ft_print(char c, va_list ap, char *flg);
int		ft_putchar_sp(char c);
int		ft_print_flg(char c, va_list ap, char *flg);
int		ft_print_simple(char c, va_list ap);
int		ft_print_chars(char c, va_list ap);
int		ft_print_num(char c, va_list ap);
int		ft_print_hex(char c, va_list ap);
int		ft_putstr_sp_flg(char *str, int slen);
int		ft_putpadding(int len, char c);
int		ft_print_chars_flg(char c, va_list ap, char *flg);
int		ft_print_num_flg(char c, va_list ap, char *flg);
int		ft_print_hex_flg(char c, va_list ap, char *flg);
int		ft_frst_pdng(char *flg);
int		ft_scnd_pdng(char *flg);
int		ft_isinflag(char *flg, char c);
int		ft_plusandspacecheck(char *flg);
int		ft_putstr_flg(char *str, char *flg);
int		ft_putchar_sp_flg(char ch, char *flg);
int		ft_putnbr_unb_flg(unsigned int unb, char *flg);
int		ft_putnbr_flg(int nb, char *flg);
int		ft_puthex_ptr_flg(uintptr_t p, char *flg);
int		ft_puthex_flg(int hex, int ver, char *flg);
int		ft_putflg_start(char *flg, char c);
int		ft_putflg_zero(char *flg, int slen, int sign);
int		ft_putflg_spc(char *flg, int slen, char c, int sign);
int		ft_putflg_checklen(char *flg, char c);
int		ft_putflgchars_aft(char *flg, int slen, int len);
int		ft_isspec(char c, char *base);
char	*ft_takeflag(char *s, int i);
void	ft_flgspc_utils_prep(char c, char *flg, int slen);
void	ft_putnbr_unb(unsigned int unb);
void	ft_putnbr(int nb);
void	ft_puthex_ptr(uintptr_t p);
void	ft_puthex(unsigned int hex, int ver);
size_t	ft_strlen(const char *s);

#endif
