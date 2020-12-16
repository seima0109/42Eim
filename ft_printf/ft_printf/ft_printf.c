/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:03:30 by stomonoh          #+#    #+#             */
/*   Updated: 2020/12/16 18:14:25 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_persent(t_in *test, va_list *ap, size_t *count)
{
	if (test->type == 'c')
		print_type_c(test, va_arg(*ap, int), count);
	else if (test->type == 's')
		print_type_s(test, va_arg(*ap, char *), count);
	else if (test->type == 'p')
		print_type_p(test, (long)va_arg(*ap, void *), count);
	else if (test->type == 'd' || test->type == 'i')
		print_type_id(test, va_arg(*ap, int), count);
	else if (test->type == 'u')
		print_type_u(test, va_arg(*ap, unsigned int), count);
	else if (test->type == 'x' || test->type == 'X')
		print_type_x(test, va_arg(*ap, unsigned int), count);
	else if (test->type == '%')
		print_type_c(test, '%', count);
}

const char	*conf_2(const char *format, va_list *ap, t_in *test, size_t *count)
{
	test->width = -1;
	if (*format == '.')
	{
		format++;
		if (!ft_isdigit(*format))
			if (*format == '*')
			{
				test->width = va_arg(*ap, int);
				format++;
			}
			else
				test->width = 0;
		else
		{
			test->width = ft_atoi((char *)format);
			while (ft_isdigit(*format))
				format++;
		}
	}
	if (!*format)
		return (format);
	test->type = *format++;
	print_persent(test, ap, count);
	return (format);
}

const char	*confirm(const char *format, va_list *ap, t_in *test, size_t *count)
{
	while (*format == '-' || *format == '0')
	{
		test->flag = (*format == '0' && test->flag != -1) ? 0 : -1;
		format++;
	}
	while (ft_isdigit(*format))
	{
		if (*(format - 1) < '1' || '9' < *(format - 1))
			test->mini = ft_atoi((char *)format);
		format++;
	}
	if (*format == '*')
	{
		test->mini = va_arg(*ap, int);
		if (test->mini < 0)
		{
			test->flag = -1;
			test->mini *= -1;
		}
		format++;
	}
	return (conf_2(format, ap, test, count));
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	size_t	count;
	t_in	*test;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			test = malloc(sizeof(t_info));
			test->flag = 1;
			test->mini = 0;
			format = confirm(++format, &ap, test, &count);
			free(test);
		}
		else
		{
			write(1, format, 1);
			format++;
			(count)++;
		}
	}
	va_end(ap);
	return (count);
}
