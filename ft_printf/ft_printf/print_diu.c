/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:36:38 by stomonoh          #+#    #+#             */
/*   Updated: 2020/12/16 17:23:38 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_num(unsigned int num)
{
	char *dec;

	dec = "0123456789";
	if (num < 10)
	{
		write(1, &dec[num], 1);
		return ;
	}
	print_num(num / 10);
	write(1, &dec[num % 10], 1);
}

void	print_type_u(info *test, unsigned int num, size_t *count)
{
	int				digit;
	int				len;
	int				i;

	digit = test->width == 0 ? 0 : 1;
	len = num;
	while ((len /= 10))
		digit++;
	len = digit < test->width ? test->width : digit;
	*count += len < test->mini ? test->mini : len;
	i = 0;
	while (test->flag != -1 && test->mini - i++ > len)
		write(1, (test->flag == 0 && test->width == -1) ? "0" : " ", 1);
	i = 0;
	while (len - i++ > digit)
		write(1, "0", 1);
	if (test->width != 0)
		print_num(num);
	while (test->flag == -1 && test->mini-- > len)
		write(1, " ", 1);
}

void	print_type_id(info *test, int num, size_t *count)
{
	int				digit;
	int				len;
	//int				i;
	unsigned int	new;

	digit = num < 0 ? 2 : 1;
	digit = test->width == 0 ? 0 : digit;
	test->width = (test->width > 0 && num < 0) ? test->width + 1 : test->width;
	len = num;
	new = num < 0 ? -num : num;
	while ((len /= 10))
		digit++;
	len = digit < test->width ? test->width : digit;
	*count += len < test->mini ? test->mini : len;
	if (!(test->flag == 0 && test->width == -1) && test->flag != -1)
	{//0フラグ+精度なし、または-フラグ、のどちらでもない場合(左詰めでも0うめでもない場合)
		while (test->mini > len && test->mini-- > 0)
			write(1, " ", 1);
	}
	if (num < 0)
		write(1, "-", 1);
	print_type_id_2(test, len, digit, new);
	/*i = 0;
	while (test->flag != -1 && test->mini - i++ > len)
		write(1, (test->flag == 0 && test->width == -1) ? "0" : " ", 1);
	i = 0;
	while (len - i++ > digit)
		write(1, "0", 1);
	if (test->width != 0)
		print_num(new);
	while (test->flag == -1 && test->mini-- > len)
		write(1, " ", 1);*/
}

void	print_type_id_2(info *test, int len, int digit, long num)
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
		if (test->width != 0)
			print_num(num);
		while (test->flag == -1 && test->mini-- > len)
			write(1, " ", 1);
	}
	if (test->type == 'p')
	{
		if (test->flag == 0 || test->width != -1)
		{
			while (test->width != -1 && test->width + 2 - i++ > digit)
				write(1, "0", 1);
			while (test->width == -1 && test->mini-- - digit)
				write(1, "0", 1);
		}
		if (test->width != 0 || num != 0)
			print_hex(0, num);
		while (test->flag == -1 && (test->mini - len) > 0 && test->mini-- > 0)
			write(1, " ", 1);
	}
}