/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:41:50 by stomonoh          #+#    #+#             */
/*   Updated: 2020/10/26 13:50:47 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;

	p = buf;
	ch = (unsigned char)c;
	while (n-- > 0)
		*p++ = ch;
	return (buf);
}
