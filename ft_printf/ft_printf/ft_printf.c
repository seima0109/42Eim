#include "ft_printf.h"
#include "libft.h"

void	print_persent(info *test, va_list *ap, size_t *count)
{
	if (test->type == 'c')
		print_type_c(test, va_arg(*ap, int), count);
	else if (test->type == 's')
		print_type_s(test, va_arg(*ap, char *), count);
	else if (test->type == 'p')
		print_type_p(test, (size_t)va_arg(*ap, void *), count);
	else if (test->type == 'd' || test->type == 'i')
		print_type_id(test, va_arg(*ap, int), count);
	else if (test->type == 'u')
		print_type_u(test, va_arg(*ap, unsigned int), count);
	else if (test->type == 'x' || test->type == 'X')
		print_type_xX(test, va_arg(*ap, int), count);
	else if (test->type == '%')
		print_type_c(test, '%', count);
}

const char	*second_confirm(const char *format, va_list *ap, info *test, size_t *count)
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
	test->type = *format++;
	//
	//printf("\nflag = %d width = %d mini = %d type = %c\n", test->flag, test->width, test->mini, test->type);
	//
	print_persent(test, ap, count);
	return (format);
}

const char    *confirm(const char *format, va_list *ap, size_t *count)
{
	info *test;

	test = malloc(sizeof(info));
	test->flag = 1;
	test->mini = 0;
	while (*format == '-' || *format == '0')
	{
		if (*format == '-')
			test->flag = -1;
		else if (*format == '0' && test->flag == 1)
			test->flag = 0;
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
	return (second_confirm(format, ap, test, count));
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	size_t	count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			format = confirm(++format, &ap, &count);
		else
		{
			write (1, format, 1);
			format++;
			(count)++;
		}
	}
	va_end(ap);
	return (count);//文字数
}