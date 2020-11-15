/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stomonoh <stomonoh@student.42tokyo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:38:30 by stomonoh          #+#    #+#             */
/*   Updated: 2020/10/30 12:06:44 by stomonoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;
	int		i;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1) - 1;
	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]))
			i++;
		else
			break ;
	}
	while (len > i)
	{
		if (!ft_strchr(set, s1[len]))
			break ;
		len--;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len - i + 2))))
		return (NULL);
	ft_strlcpy(str, &s1[i], len - i + 2);
	return (str);
}
