/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 22:20:16 by stomonoh          #+#    #+#             */
/*   Updated: 2020/10/31 03:27:35 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	while (i < len)
	{
		p1[i] = p2[i];
		if (p2[i] == ch)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
