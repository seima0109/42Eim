/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:34:09 by stomonoh          #+#    #+#             */
/*   Updated: 2020/10/30 12:19:27 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*cp;
	char	*ans;

	len = ft_strlen(str);
	if (!(cp = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ans = cp;
	while (len-- > 0)
		*cp++ = *str++;
	*cp = '\0';
	return (ans);
}
