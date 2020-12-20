/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:36:38 by stomonoh          #+#    #+#             */
/*   Updated: 2020/12/20 20:20:36 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_num(long num, int zero, size_t *count)
{
	char *dec;

	if (num < 0)
	{
		*count += write(1, "-", 1);
		num *= -1;
	}
	while (zero-- > 0)
		*count += write(1, "0", 1);
	dec = "0123456789";
	if (num < 10)
	{
		*count += write(1, &dec[num], 1);
		return ;
	}
	print_num(num / 10, 0, count);
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
	if (test->width != 0 || num != 0)
		print_num(num, zero, count);
	if (test->flag == -1)
		while (space-- > 0)
			*count += write(1, " ", 1);
}

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
	if (test->width != 0 || num != 0)
		print_num(num, zero, count);
	while (test->flag == -1 && space-- > 0)
		*count += write(1, " ", 1);
}