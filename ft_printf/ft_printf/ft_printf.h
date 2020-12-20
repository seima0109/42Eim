/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:58:01 by stomonoh          #+#    #+#             */
/*   Updated: 2020/12/20 20:20:53 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct{
	int		flag;
	int		mini;
	int		width;
	char	type;
}			t_in;

int			ft_printf(const char *str, ...);
void		print_type_c(t_in *test, unsigned char c, size_t *count);
void		print_type_s(t_in *test, char *str, size_t *count);
void		print_type_p(t_in *test, size_t p, size_t *count);
void		print_type_x(t_in *test, size_t num, size_t *count);
void		print_type_u(t_in *test, size_t num, size_t *count);
void		print_type_id(t_in *test, int num, size_t *count);
void		print_hex(char type, size_t num, size_t *count);
void		print_num(long num, int zero, size_t *count);
void		free_box(t_in *test);

#endif
