/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:57:04 by stomonoh          #+#    #+#             */
/*   Updated: 2020/11/01 10:48:02 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!little[0])
		return ((char *)big);
	if ((ft_strlen(big) < ft_strlen(little)) || len == 0)
		return (NULL);
	while (big[i] && i + ft_strlen(little) <= len)
	{
		if (!(ft_strncmp(&big[i], little, ft_strlen(little))))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
