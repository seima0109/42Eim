/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 10:57:53 by stomonoh          #+#    #+#             */
/*   Updated: 2020/10/26 13:50:13 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	unsigned char		*p1;
	unsigned const char	*p2;

	if (buf1 == NULL && buf2 == NULL)
		return (NULL);
	p1 = buf1;
	p2 = buf2;
	if (p1 > p2)
	{
		while (n > 0)
		{
			p1[n - 1] = p2[n - 1];
			n--;
		}
	}
	else
	{
		while (n-- > 0)
			*p1++ = *p2++;
	}
	return (buf1);
}
