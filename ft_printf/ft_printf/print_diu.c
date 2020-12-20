/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:36:38 by stomonoh          #+#    #+#             */
/*   Updated: 2020/12/20 19:49:07 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_num(unsigned int num, size_t *count)
{
	char *dec;

	dec = "0123456789";
	if (num < 10)
	{
		*count += write(1, &dec[num], 1);
		return ;
	}
	print_num(num / 10, count);
	*count += write(1, &dec[num % 10], 1);
}

void	print_type_u(t_in *test, size_t num, size_t *count)
{
	int		ulen;
	int		zero;
	int		space;
	size_t	utmp;

	ulen = (!test->width && !num) ? 0 : 1;
	utmp = num;
	while ((utmp/=10))
		ulen++;
	zero = (test->width > ulen) ? test->width - ulen : 0;
	zero = (test->width < 0 && test->flag == 0) ? test->mini - ulen : zero;
	zero = (zero < 0) ? 0 : zero;
	space = test->mini - zero - ulen;
	if (test->flag != -1)
		while (space-- > 0)
			*count += write(1, " ", 1);
	while (zero-- > 0)
		*count += write(1, "0", 1);
	if (test->width != 0 || num != 0)
		print_num(num, count);
	if (test->flag == -1)
		while (space-- > 0)
			*count += write(1, " ", 1);
}
/*
void	print_type_id(t_in *test, int num, size_t *count)
{
	int				digit;
	int				len;
	unsigned int	new;

	digit = num < 0 ? 2 : 1;
	digit = (test->width == 0 && num == 0) ? 0 : digit;
	test->width = (test->width > 0 && num < 0) ? test->width + 1 : test->width;
	len = num;
	new = num < 0 ? -num : num;
	while ((len /= 10))
		digit++;
	len = digit < test->width ? test->width : digit;
	*count += len < test->mini ? test->mini : len;
	*count -= num < 0 ? digit - 1 : digit;
	if (!(test->flag == 0 && test->width == -1) && test->flag != -1)
	{//0フラグ+精度なし、または-フラグ、のどちらでもない場合(左詰めでも0うめでもない場合)
		while (test->mini > len && test->mini-- > 0)
			write(1, " ", 1);
	}
	if (num < 0)
		write(1, "-", 1);
	print_type_id_2(test, len, digit, new, count);
}

void	print_type_id_2(t_in *test, int len, int digit, long num, size_t *count)
{
	int	i;

	if (test->type == 'i' || test->type == 'd')
	{
		i = 0;
		while (test->flag != -1 && test->mini - i++ > len)
			write(1, (test->flag == 0 && test->width == -1) ? "0" : " ", 1);
		i = 0;
		while (len - i++ > digit)
			write(1, "0", 1);
		if (test->width != 0 || num != 0)
			print_num(num, count);
		while (test->flag == -1 && test->mini-- > len)
			write(1, " ", 1);
	}
}*/

void	print_type_id(t_in *test, int num, size_t *count)
{
	int	len;
	int	tmp;
	int	zero;
	int	space;

	len = num < 0 ? 2 : 1;
	len = (!test->width && !num) ? 0 : len;
	test->width = (test->width > 0 && num < 0) ? test->width + 1 : test->width;
	tmp = num;
	while ((tmp /= 10))
		len++;
	zero = (test->width > len) ? test->width - len : 0;
	zero = (test->flag == 0 && test->width < 0) ? test->mini - len : zero;
	zero = zero < 0 ? 0 : zero;
	space = test->mini - zero - len;
	if (test->flag != -1)
		while (space-- > 0)
			*count += write(1, " ", 1);
	if (num < 0)
	{
		num = -num;
		*count += write(1, "-", 1);
	}
	while (zero-- > 0)
		*count += write(1, "0", 1);
	if (test->width != 0 || num != 0)
		print_num(num, count);
	if (test->flag == -1)
		while (space-- > 0)
			*count += write(1, " ", 1);
}