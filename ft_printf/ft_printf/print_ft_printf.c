/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:36:43 by stomonoh          #+#    #+#             */
/*   Updated: 2020/12/20 18:48:55 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type_c(t_in *test, unsigned char c, size_t *count)
{
	*count += test->mini != 0 ? test->mini : 1;
	if (test->flag != -1)
	{
		while (test->mini-- - 1 && test->mini > 0)
			write(1, test->flag == 0 ? "0" : " ", 1);
	}
	write(1, &c, 1);
	if (test->flag == -1)
	{
		while (test->mini-- - 1 && test->mini > 0)
			write(1, " ", 1);
	}
}

void	print_type_s(t_in *test, char *str, size_t *count)
{
	int len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	len = (len < test->width || test->width <= -1) ? len : test->width;
	*count += test->mini > len ? test->mini : len;
	if (test->flag != -1)
	{
		while (test->mini - len > 0 && test->mini-- > 0)
			write(1, test->flag == 0 ? "0" : " ", 1);
	}
	write(1, str, len);
	if (test->flag == -1)
	{
		while (test->mini - len > 0 && test->mini-- > 0)
			write(1, " ", 1);
	}
}

void	print_hex(char type, size_t num, size_t *count)
{
	const char	*hex;

	if (type != 'X')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (num < 16)
	{
		*count += write(1, &hex[num], 1);
		return ;
	}
	print_hex(type, num / 16, count);
	*count += write(1, &hex[num % 16], 1);
}
/*
void	print_type_p(t_in *test, long p, size_t *count)
{
	int		digit;
	long	len;//桁数と精度と高い方が入る

	digit = (test->width == 0 && p == 0) ? 2 : 3;
	len = p;
	while ((len /= 16))
		digit++;
	len = digit < test->width + 2 ? test->width + 2 : digit;
	*count += len < test->mini ? test->mini : len;
	*count -= digit - 2;
	if (!(test->flag == 0 && test->width == -1) && (test->flag != -1))//0フラグ+精度なし、は-フラグ、のどちらでもない場合(左詰めでも0うめでもない場合)
		while (test->mini-- > len && test->mini > 0)
			write(1, " ", 1);
	write(1, "0x", 2);
	while (test->width != -1 && test->width + 2 > digit++)
		write(1, "0", 1);
	while (test->flag == 0 && test->width == -1 && test->mini-- - digit)
		write(1, "0", 1);
	if (test->width != 0 || p != 0)
		print_hex(0, p, count);
	while (test->flag == -1 && (test->mini - len) > 0 && test->mini-- > 0)
		write(1, " ", 1);
}*/
void	print_type_p(t_in *test, size_t p, size_t *count)
{
	int		plen;
	int		zero;
	int 	space;
	size_t	ptmp;

	plen = (!p && !test->width) ? 0 : 1;
	ptmp = p;
	while ((ptmp /= 16))
		plen++;
	zero = (test->width < 0 && test->flag == 0)
			? test->width - plen - 2 : test->width - plen;
	space = (zero > 0) ? test->mini - zero - plen - 2 : test->mini - plen - 2;
	if (test->flag != -1)
		while (space-- > 0)
			*count += write(1, " ", 1);
	*count += write(1, "0x", 2);
	while (zero-- > 0)
		*count += write(1, "0", 1);
	if (test->width != 0 || p != 0)
		print_hex('p', p, count);
	if (test->flag == -1)
		while (space-- > 0)
			*count += write(1, " ", 1);
}
/*
void	print_type_x(t_in *test, size_t num, size_t *count)
{
	int	digit;
	int	len;
	int	i;

	len = num;
	digit = (test->width == 0 && num == 0) ? 0 : 1;
	while ((len /= 16))
		digit++;
	len = digit < test->width ? test->width : digit;
	*count += len < test->mini ? test->mini : len;
	*count -= digit;
	i = 0;
	while (test->flag != -1 && test->mini != 0 && test->mini - i++ > len)
		write(1, (test->width == -1 && test->flag == 0) ? "0" : " ", 1);
	i = 0;
	while (test->width != -1 && len - i++ > digit)
		write(1, "0", 1);
	if (test->width != 0 || num != 0)
		print_hex(test->type, num, count);
	while (test->flag == -1 && test->mini-- > len)
		write(1, " ", 1);
}*/
void	print_type_x(t_in *test, size_t num, size_t *count)
{
	int				xlen;
	int				space;
	int				zero;
	unsigned int	xtmp;

	xtmp = num;
	xlen = (!num && !test->width) ? 0 : 1;
	while ((xtmp/16))
		xlen++;
	zero = (test->width > xlen) ? test->width - xlen : 0;
	zero = (test->width < 0 && test->flag == 0) ? test->mini - xlen : zero;
	zero = (zero < 0) ? 0 :zero;
	space = test->mini - zero - xlen;
	if (test->flag != -1)
		while (space-- > 0)
			*count += write(1, " ", 1);
	while (zero-- > 0)
		*count += write(1, "0", 1);
	if (!(!test->width && !num))
		print_hex(test->type, num, count);
	if (test->flag == -1)
		while (space-- > 0)
			*count += write(1, " ", 1);
}