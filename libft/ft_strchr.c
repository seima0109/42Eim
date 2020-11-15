/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:33:45 by stomonoh          #+#    #+#             */
/*   Updated: 2020/10/19 23:10:23 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		if (!(str[i]))
			break ;
		i++;
	}
	return (NULL);
}
