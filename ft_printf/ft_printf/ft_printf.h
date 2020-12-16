/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:58:01 by stomonoh          #+#    #+#             */
/*   Updated: 2020/12/16 18:37:08 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "../../libft/libft.h"

typedef struct{
	int		flag;
	int		mini;
	int		width;
	char	type;
}			t_in;

int			ft_printf(const char *str, ...);
void		print_type_c(t_in *test, unsigned char c, size_t *count);
void		print_type_s(t_in *test, char *str, size_t *count);
void		print_type_p(t_in *test, long p, size_t *count);
void		print_type_x(t_in *test, unsigned int num, size_t *count);
void		print_type_u(t_in *test, unsigned int num, size_t *count);
void		print_type_id(t_in *test, int num, size_t *count);
void		print_type_id_2(t_in *test, int len, int digit, long num, size_t *count);
void		print_hex(char type, size_t num);
void		print_num(unsigned int num, size_t *count);
void		free_box(t_in *test);

#endif
