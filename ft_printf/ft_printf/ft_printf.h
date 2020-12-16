/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:58:01 by stomonoh          #+#    #+#             */
/*   Updated: 2020/12/16 18:07:06 by stomonoh         ###   ########.fr       */
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
}			t_info;

int			ft_printf(const char *str, ...);
void		print_type_c(t_info *test, unsigned char c, size_t *count);
void		print_type_s(t_info *test, char *str, size_t *count);
void		print_type_p(t_info *test, long p, size_t *count);
void		print_type_x(t_info *test, unsigned int num, size_t *count);
void		print_type_u(t_info *test, unsigned int num, size_t *count);
void		print_type_id(t_info *test, int num, size_t *count);
void		print_type_id_2(t_info *test, int len, int digit, long num);
void		print_hex(char type, size_t num);
void		print_num(unsigned int num);
void		free_box(t_info *test);

#endif
