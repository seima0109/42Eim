/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:37:36 by stomonoh          #+#    #+#             */
/*   Updated: 2020/10/26 14:26:51 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *str1, const char *str2, size_t size)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (size <= len1)
		return (size + len2);
	i = len1;
	while (*str2 && i < size - 1)
		str1[i++] = *str2++;
	str1[i] = '\0';
	return (len1 + len2);
}
