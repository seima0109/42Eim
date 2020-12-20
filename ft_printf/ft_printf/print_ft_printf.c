/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:36:43 by stomonoh          #+#    #+#             */
/*   Updated: 2020/12/20 20:26:53 by stomonoh         ###   ########.fr       */
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

void	print_type_p(t_in *test, size_t p, size_t *count)
{
	int		plen;
	int		zero;
	int		space;
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

void	print_type_x(t_in *test, size_t num, size_t *count)
{
	int		xlen;
	int		space;
	int		zero;
	size_t	xtmp;

	xtmp = num;
	xlen = (!num && !test->width) ? 0 : 1;
	while ((xtmp /= 16))
		xlen++;
	zero = (test->width > xlen) ? test->width - xlen : 0;
	zero = (test->width < 0 && test->flag == 0) ? test->mini - xlen : zero;
	zero = (zero < 0) ? 0 : zero;
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
