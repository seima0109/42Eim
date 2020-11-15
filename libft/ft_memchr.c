/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:17:03 by stomonoh          #+#    #+#             */
/*   Updated: 2020/10/26 14:03:42 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;

	ch = (unsigned char)c;
	p = (unsigned char *)buf;
	while (n--)
	{
		if (*p == ch)
			return (p);
		p++;
	}
	return (NULL);
}
