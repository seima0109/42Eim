/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:53:47 by stomonoh          #+#    #+#             */
/*   Updated: 2020/10/30 12:08:08 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *str1, const char *str2, size_t size)
{
	size_t	i;

	if (!str1 || !str2)
		return (0);
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && str2[i])
		{
			str1[i] = str2[i];
			i++;
		}
		str1[i] = '\0';
	}
	return (ft_strlen(str2));
}
