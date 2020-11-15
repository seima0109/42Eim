/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:25:51 by stomonoh          #+#    #+#             */
/*   Updated: 2020/10/26 17:54:20 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*p;

	if (!(p = (char *)malloc(sizeof(char) * n * size)))
		return (NULL);
	ft_bzero(p, n * size);
	return ((void *)p);
}
