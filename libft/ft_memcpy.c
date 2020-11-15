/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:45:26 by stomonoh          #+#    #+#             */
/*   Updated: 2020/10/31 03:24:41 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	unsigned char		*p1;
	unsigned const char	*p2;

	if (buf1 == NULL && buf2 == NULL)
		return (NULL);
	p1 = buf1;
	p2 = buf2;
	while (n--)
		*p1++ = *p2++;
	return (buf1);
}
