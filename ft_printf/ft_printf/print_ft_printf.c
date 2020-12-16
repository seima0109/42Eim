/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:36:43 by stomonoh          #+#    #+#             */
/*   Updated: 2020/12/16 17:49:41 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type_c(info *test, unsigned char c, size_t *count)
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

void	print_type_s(info *test, char *str, size_t *count)
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

void	print_hex(char type, size_t num)
{
	const char	*hex;

	if (type != 'X')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (num < 16)
	{
		write(1, &hex[num], 1);
		return ;
	}
	print_hex(type, num / 16);
	write(1, &hex[num % 16], 1);
}

void	print_type_p(info *test, long p, size_t *count)
{
	int		digit;
	long	len;//桁数と精度と高い方が入る
	//int		i;

	//i = 0;
	digit = (test->width == 0 && p == 0) ? 2 : 3;//0x と　数字1桁目
	len = p;
	while ((len /= 16))
		digit++;
	len = digit < test->width + 2 ? test->width + 2 : digit;
	*count += len < test->mini ? test->mini : len;
	if (!(test->flag == 0 && test->width == -1) && (test->flag != -1))//0フラグ+精度なし、は-フラグ、のどちらでもない場合(左詰めでも0うめでもない場合)
		while (test->mini-- > len && test->mini > 0)
			write(1, " ", 1);
	write(1, "0x", 2);
	while (test->width != -1 && test->width + 2 /*- i++*/ > digit++)
		write(1, "0", 1);
	while (test->flag == 0 && test->width == -1 && test->mini-- - digit)
		write(1, "0", 1);
	if (test->width != 0 || p != 0)
		print_hex(0, p);
	while (test->flag == -1 && (test->mini - len) > 0 && test->mini-- > 0)
		write(1, " ", 1);
}

void	print_type_xX(info *test, unsigned int num, size_t *count)
{
	int	digit;
	int	len;
	int	i;

	len = num;
	digit = test->width == 0 ? 0 : 1;
	while ((len /= 16))
		digit++;
	len = digit < test->width ? test->width : digit;
	*count += len < test->mini ? test->mini : len;
	i = 0;
	while (test->flag != -1 && test->mini != 0 && test->mini - i++ > len)
		write(1, (test->width == -1 && test->flag == 0) ? "0" : " ", 1);
	i = 0;
	while (test->width != -1 && len - i++ > digit)
		write(1, "0", 1);
	if (test->width != 0)
		print_hex(test->type, num);
	while (test->flag == -1 && test->mini-- > len)
		write(1, " ", 1);
}
